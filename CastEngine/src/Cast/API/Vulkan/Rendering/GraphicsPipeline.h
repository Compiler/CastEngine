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


    };

}