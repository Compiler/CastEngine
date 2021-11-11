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
    
    

    struct ShaderPipelineData{
        VkPipelineShaderStageCreateInfo createInfo;
        VkShaderModule shaderModule;
    };
    class VulkanShaderProgram : public ShaderProgram{

        private:
            VkShaderModule _createShaderModule(const std::vector<char>& code);
            VkShaderModule _createShaderModule(const std::vector<uint32_t>& code);
            std::vector<ShaderPipelineData> _shaderCreationData;
            std::vector<VkPipelineShaderStageCreateInfo> _shaderCreateInfo;

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

            std::vector<ShaderPipelineData>& getShaderCreationData(){return this->_shaderCreationData;}
            std::vector<VkPipelineShaderStageCreateInfo>& getShaderCreateInfo(){return this->_shaderCreateInfo;}
            //PipeLineShaderInfo load(const char* vertFilePath, const char* fragFilePath);
            inline bool isSet(){return true;}
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
            }
    };

}