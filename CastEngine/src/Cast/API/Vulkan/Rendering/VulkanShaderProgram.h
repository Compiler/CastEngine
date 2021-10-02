#pragma once
#include <vulkan/vulkan.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <vector>
namespace Cast{

    class VulkanShaderProgram{

        private:
            VkShaderModule _createShaderModule(VkDevice& logicalDevice, const std::vector<char>& code);
        
        public:
            VulkanShaderProgram()= default;
            VulkanShaderProgram(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath);
            void load(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath);

    };

}