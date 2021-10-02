#pragma once
#include <vulkan/vulkan.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <string>
#include <iostream>
#include <vector>
namespace Cast{
    
    struct PipeLineShaderInfo{
        VkPipelineShaderStageCreateInfo vert_data;
        VkPipelineShaderStageCreateInfo frag_data;
        VkShaderModule vert_module, frag_module;
    };
    class VulkanShaderProgram{

        private:
            bool _isSet = false;
            VkShaderModule _createShaderModule(VkDevice& logicalDevice, const std::vector<char>& code);
            PipeLineShaderInfo _pipelineData;
        public:
            VulkanShaderProgram()= default;
            VulkanShaderProgram(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath);
            PipeLineShaderInfo load(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath);
            inline PipeLineShaderInfo getPipeLineShaderInfo(){return _pipelineData;}
            inline bool isSet(){return _isSet;}

    };

}