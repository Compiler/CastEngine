#pragma once
#include <vulkan/vulkan.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/Core/Rendering/Shader/ShaderProgram.h>
#include <string>
#include <iostream>
#include <vector>
namespace Cast{
    
    
    struct PipeLineShaderInfo{
        VkPipelineShaderStageCreateInfo vert_data;
        VkPipelineShaderStageCreateInfo frag_data;
        VkShaderModule vert_module, frag_module;
    };
    class VulkanShaderProgram : public ShaderProgram{

        private:
            bool _isSet = false;
            VkShaderModule _createShaderModule(VkDevice& logicalDevice, const std::vector<char>& code);
            PipeLineShaderInfo _pipelineData;
        public:
            VulkanShaderProgram()= default;

            //TODO Implement these
            void loadShader(const char* shaderFilePath, Shader::ShaderType shaderType){CAST_WARN("THIS FUNCTION DOES NOTHING~!!!!");}
            void loadShader(std::initializer_list<Shader> shaders){CAST_WARN("THIS FUNCTION DOES NOTHING~!!!!");}
            void compile(){CAST_WARN("THIS FUNCTION DOES NOTHING~!!!!");}
            void use(){CAST_WARN("THIS FUNCTION DOES NOTHING~!!!!");}
            //TODO end


            VulkanShaderProgram(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath);
            PipeLineShaderInfo load(VkDevice& logicalDevice, const char* vertFilePath, const char* fragFilePath);
            inline PipeLineShaderInfo getPipeLineShaderInfo(){return _pipelineData;}
            inline bool isSet(){return _isSet;}
            ~VulkanShaderProgram(){}

    };

}