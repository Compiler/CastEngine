#pragma once
#include <Cast/API/Vulkan/Rendering/VulkanShaderProgram.h>
#include <Cast/API/Vulkan/VulkanIncludeWrapper.h>
#include <Cast/API/Vulkan/Rendering/VulkanInstance.h>
namespace Cast{

    class GraphicsPipeline{

        private:
            VulkanShaderProgram _shaderProgram;
            const char* _name;
            //PipeLineShaderInfo _shaderInfo;
            //VkPipelineShaderStageCreateInfo _shaderStages[2];

            VkPipeline _graphicsPipeline;
            VkPipelineLayout _graphicsPipelineLayout;

            VkDescriptorSetLayout _descriptorSetLayout;


        public:
            GraphicsPipeline() = default;
            GraphicsPipeline(VkDevice logicalDevice, const char* name, VulkanShaderProgram program, VkExtent2D& swapExtent, VkRenderPass& renderPass);
            void load(VkDevice logicalDevice, const char* name, VulkanShaderProgram program, VkExtent2D& swapExtent, VkRenderPass& renderPass);
            void createDescriptorSetLayout(VkDevice& logicalDevice);
            

            inline VkPipeline getPipeline(){return this->_graphicsPipeline;}
            inline VulkanShaderProgram& getShaderProgram(){return this->_shaderProgram;}
            inline VkDescriptorSetLayout& getDescriptorSetLayout(){return this->_descriptorSetLayout;}
            inline VkPipelineLayout& getPipelineLayout(){return this->_graphicsPipelineLayout;}



            void unload(VkDevice& logicalDevice);




            inline static VkVertexInputBindingDescription getBindingDescription(){
                VkVertexInputBindingDescription bindingInfo{};
                bindingInfo.binding = 0;
                bindingInfo.stride = sizeof(Cast::VertexTemplate);
                bindingInfo.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
                return bindingInfo;
            }


            inline static std::array<VkVertexInputAttributeDescription, 7> getAttributeDescriptions() {
                std::array<VkVertexInputAttributeDescription, 7> attributeDescriptions{};
                attributeDescriptions[0].binding = 0;
                attributeDescriptions[0].location = 0;
                attributeDescriptions[0].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[0].offset = offsetof(VertexTemplate, position);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->position)));

                attributeDescriptions[1].binding = 0;
                attributeDescriptions[1].location = 1;
                attributeDescriptions[1].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[1].offset = offsetof(VertexTemplate, color);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));

                attributeDescriptions[2].binding = 0;
                attributeDescriptions[2].location = 2;
                attributeDescriptions[2].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[2].offset = offsetof(VertexTemplate, normal);//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));

                attributeDescriptions[3].binding = 0;
                attributeDescriptions[3].location = 3;
                attributeDescriptions[3].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[3].offset = offsetof(VertexTemplate, model) + sizeof(glm::vec4) * 0;//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));

                attributeDescriptions[4].binding = 0;
                attributeDescriptions[4].location = 4;
                attributeDescriptions[4].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[4].offset = offsetof(VertexTemplate, model) + sizeof(glm::vec4) * 1;//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));


                attributeDescriptions[5].binding = 0;
                attributeDescriptions[5].location = 5;
                attributeDescriptions[5].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[5].offset = offsetof(VertexTemplate, model) + sizeof(glm::vec4) * 2;//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));


                attributeDescriptions[6].binding = 0;
                attributeDescriptions[6].location = 6;
                attributeDescriptions[6].format = VK_FORMAT_R32G32B32A32_SFLOAT;
                attributeDescriptions[6].offset = offsetof(VertexTemplate, model) + sizeof(glm::vec4) * 3;//((::size_t)&reinterpret_cast<char const volatile&>((((Vertex_Tmp*)0)->color)));

                return attributeDescriptions;
            }

    };

}