#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/API/Vulkan/VulkanIncludeWrapper.h>

namespace Cast{

    
    class VulkanBuffer{
        
        private:
            VkPhysicalDevice _physicalDevice;
            VkDevice _logicalDevice;

            VkBuffer _buffer;
            VkDeviceMemory _bufferMemory;
        public:
            VulkanBuffer() = default;
            VulkanBuffer(VkPhysicalDevice& physicalDevice, VkDevice& logicalDevice):_physicalDevice(physicalDevice), _logicalDevice(logicalDevice){}
            void load(VkPhysicalDevice& physicalDevice, VkDevice& logicalDevice){this->_physicalDevice = physicalDevice; this->_logicalDevice = logicalDevice;}
            uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) {
                VkPhysicalDeviceMemoryProperties memProperties;
                vkGetPhysicalDeviceMemoryProperties(_physicalDevice, &memProperties);
                for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
                     if ((typeFilter & (1 << i)) && (memProperties.memoryTypes[i].propertyFlags & properties) == properties){
                        return i;
                    }
                }
                return 4444;
                CAST_ERROR("failed to find suitable memory type!");
            }

            void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties){
                if(!_physicalDevice || !_logicalDevice){
                    CAST_FATAL("No device set in buffer, can't create data.");
                }
                VkBufferCreateInfo bufferInfo{};
                bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
                bufferInfo.usage = usage;
                bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;
                bufferInfo.size = size;

                if (vkCreateBuffer(_logicalDevice, &bufferInfo, nullptr, &_buffer) != VK_SUCCESS) {
                    CAST_ERROR("failed to create vertex buffer!");
                }

                VkMemoryRequirements memRequirements;
                vkGetBufferMemoryRequirements(_logicalDevice, _buffer, &memRequirements);
                VkMemoryAllocateInfo allocInfo{};
                allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
                allocInfo.allocationSize = memRequirements.size;

                allocInfo.memoryTypeIndex = findMemoryType(memRequirements.memoryTypeBits, properties);

                if (vkAllocateMemory(_logicalDevice, &allocInfo, nullptr, &_bufferMemory) != VK_SUCCESS) {
                    CAST_ERROR("failed to allocate vertex buffer memory!");
                }
                vkBindBufferMemory(_logicalDevice, _buffer, _bufferMemory, 0);

            }

            VkBuffer& getBuffer(){return this->_buffer;}
            VkDeviceMemory& getDeviceMemory(){return this->_bufferMemory;}


            inline static void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size, VkCommandPool& commandPool, VkQueue& queue, VkDevice& logicalDevice){
                VkCommandBufferAllocateInfo allocInfo{};
                allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
                allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
                allocInfo.commandPool = commandPool;
                allocInfo.commandBufferCount = 1;
                VkCommandBuffer commandBuffer;
                vkAllocateCommandBuffers(logicalDevice, &allocInfo, &commandBuffer);


                VkCommandBufferBeginInfo beginInfo{};
                beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
                beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

                vkBeginCommandBuffer(commandBuffer, &beginInfo);

                VkBufferCopy copyRegion{};
                //copyRegion.srcOffset = 0;
                //copyRegion.dstOffset = 0;
                copyRegion.size = size;
                vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);
                vkEndCommandBuffer(commandBuffer);


                VkSubmitInfo submitInfo{};
                submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
                submitInfo.commandBufferCount = 1;
                submitInfo.pCommandBuffers = &commandBuffer;

                vkQueueSubmit(queue, 1, &submitInfo, VK_NULL_HANDLE);
                vkQueueWaitIdle(queue);

                vkFreeCommandBuffers(logicalDevice, commandPool, 1, &commandBuffer);
            }


            void unload(){
                vkDestroyBuffer(_logicalDevice,_buffer, nullptr);
                vkFreeMemory(_logicalDevice, _bufferMemory, nullptr);
            }
    };

}