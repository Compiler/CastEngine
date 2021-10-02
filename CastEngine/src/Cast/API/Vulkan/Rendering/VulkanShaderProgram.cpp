#include "VulkanShaderProgram.h"

namespace Cast{
    
        VulkanShaderProgram::VulkanShaderProgram(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath){
            load(logicalDevice, vertFilePath, fragFilePath);
            _isSet = true;
        }

        PipeLineShaderInfo VulkanShaderProgram::load(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath){
            auto vertShaderCode = Cast::FileLoaderFactory::readSPV(CAST_INTERNAL_SHADER("passthrough_vert.spv"));
            auto fragShaderCode = Cast::FileLoaderFactory::readSPV(CAST_INTERNAL_SHADER("RayMarching_frag.spv"));

            VkShaderModule vertShaderModule = _createShaderModule(logicalDevice, vertShaderCode);
            VkShaderModule fragShaderModule = _createShaderModule(logicalDevice, fragShaderCode);

            VkPipelineShaderStageCreateInfo vertShaderStageInfo{};
            vertShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
            vertShaderStageInfo.module = vertShaderModule;
            vertShaderStageInfo.pName = "main";

            VkPipelineShaderStageCreateInfo fragShaderStageInfo{};
            fragShaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
            fragShaderStageInfo.module = fragShaderModule;
            fragShaderStageInfo.pName = "main";

            VkPipelineShaderStageCreateInfo shaderStages[2] = {vertShaderStageInfo, fragShaderStageInfo};
            _pipelineData = {shaderStages[0], shaderStages[1], vertShaderModule, fragShaderModule};
            return _pipelineData;
        }


        //wraps the code in a vkshadermodule object before being passed to the pipeline
        //'code' is the bytecode representation of the glsl code - spirv 
        VkShaderModule VulkanShaderProgram::_createShaderModule(VkDevice& logicalDevice, const std::vector<char>& code){
            VkShaderModuleCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            createInfo.codeSize = code.size();
            createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
            VkShaderModule shaderModule;
            if (vkCreateShaderModule(logicalDevice, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
                CAST_ERROR("failed to create shader module!");
            }
            return shaderModule;
        }

}