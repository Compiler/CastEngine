#pragma once
#include <vulkan/vulkan.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/Core/Rendering/Shader/ShaderProgram.h>
#include <Cast/Core/Rendering/Shader/ShaderParser.h>
#include <string>
#include <iostream>
#include <vector>
namespace Cast{
    
    
    struct PipeLineShaderInfo{
        VkPipelineShaderStageCreateInfo vert_data;
        VkPipelineShaderStageCreateInfo frag_data;
        VkShaderModule vert_module, frag_module;
    };

    struct ShaderPipelineData{
        VkPipelineShaderStageCreateInfo createInfo;
        VkShaderModule shaderModule;
    };
    class VulkanShaderProgram : public ShaderProgram{

        private:
            bool _isSet = false;
            VkShaderModule _createShaderModule(const std::vector<char>& code);
            VkShaderModule _createShaderModule(const std::vector<uint32_t>& code);
            PipeLineShaderInfo _pipelineData;
            std::vector<ShaderPipelineData> _shaderCreationData;

            VkDevice _logicalDevice;
        public:
            VulkanShaderProgram()= default;
            VulkanShaderProgram(VkDevice& logicalDevice):_logicalDevice(logicalDevice){};

            void loadShader(const char* shaderFilePath, Shader::ShaderType shaderType);
            void loadShader(std::initializer_list<Shader> shaders);
            //TODO Implement these
            void compile(){CAST_WARN("THIS FUNCTION DOES NOTHING~!!!!");}
            void use(){CAST_WARN("THIS FUNCTION DOES NOTHING~!!!!");}
            //TODO end

            //std::vector<ShaderPipelineData>& getShaderCreationData(){return this->_shaderCreationData;}
            VulkanShaderProgram(const char* vertFilePath, const char* fragFilePath);
            PipeLineShaderInfo load(const char* vertFilePath, const char* fragFilePath);
            inline PipeLineShaderInfo getPipeLineShaderInfo(){return _pipelineData;}
            inline bool isSet(){return _isSet;}
            ~VulkanShaderProgram(){}

        private:
            VkShaderStageFlagBits _getShaderBitFromType(Shader::ShaderType shaderType){
                switch(shaderType){
                    case Shader::ShaderType::Vertex:{
                        return VkShaderStageFlagBits::VK_SHADER_STAGE_VERTEX_BIT;
                        break;
                    }
                    case Shader::ShaderType::Fragment:{
                        return VkShaderStageFlagBits::VK_SHADER_STAGE_FRAGMENT_BIT;
                        break;
                    }
                    case Shader::ShaderType::Geometry:{
                        return VkShaderStageFlagBits::VK_SHADER_STAGE_GEOMETRY_BIT;
                        break;
                    }
                    default:
                        CAST_FATAL("Failed to deduce shaderc type");
                    }
    };

}