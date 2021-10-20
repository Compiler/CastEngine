#pragma once
#include <Cast/API/Vulkan/Rendering/VulkanShaderProgram.h>
#include <Vulkan/vulkan.h>
#include <Cast/API/Vulkan/Rendering/VulkanInstance.h>
namespace Cast{

    class GraphicsPipeline{

        private:
            VulkanShaderProgram _shaderProgram;
            const char* _name;
            PipeLineShaderInfo _shaderInfo;
            VkPipelineShaderStageCreateInfo _shaderStages[2];

        public:
            GraphicsPipeline() = default;
            GraphicsPipeline(VkDevice logicalDevice, const char* name, VulkanShaderProgram program);
            void load(VkDevice logicalDevice, const char* name, VulkanShaderProgram program);



    };

}