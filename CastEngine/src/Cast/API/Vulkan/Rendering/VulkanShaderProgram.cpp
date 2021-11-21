#include "VulkanShaderProgram.h"

namespace Cast{
    

        void VulkanShaderProgram::loadShader(const char* shaderFilePath, Shader::ShaderType shaderType){

            //TODO: Check if shaderFilePath is an spv or a glsl!!!
            VkShaderModule shader_module;
            VkShaderStageFlagBits shader_bit;
            
            std::filesystem::path path_to_shader(shaderFilePath);
            std::string fileNameOnly = std::filesystem::absolute(path_to_shader).filename().generic_string();
            if(fileNameOnly.substr(fileNameOnly.size() - 3) == "spv"){
                CAST_LOG("'{}' is already in spv format, so we may just load it!", shaderFilePath);
                auto shader_spv_format =  FileLoaderFactory::readSPV(fileNameOnly.c_str());
                shader_module = _createShaderModule(shader_spv_format);
                shader_bit = _getShaderBitFromType(shaderType);
            }else{
                std::string shader_out_path =  fileNameOnly + ".spv";
                CAST_LOG("Compiling to SPRV");
                auto shader_spv_format = ShaderParser::compileGLSLToSPRV(shaderFilePath, shader_out_path.c_str(), shaderType);
                CAST_LOG("Got SPRV Format");
                shader_module = _createShaderModule(shader_spv_format);
                shader_bit = _getShaderBitFromType(shaderType);
            }
            CAST_LOG("Creating pipe");
            VkPipelineShaderStageCreateInfo shaderStageInfo{};
            shaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            shaderStageInfo.stage = shader_bit;
            shaderStageInfo.module = shader_module;
            shaderStageInfo.pName = "main";

            _shaderCreationData.push_back({shaderStageInfo, shader_module});
            _shaderCreateInfo.push_back(shaderStageInfo);
        }
        void VulkanShaderProgram::loadShader(std::initializer_list<Shader> shaders){
            for(const auto& shader : shaders)loadShader(shader.filePath, shader.type);
        }


        //wraps the code in a vkshadermodule object before being passed to the pipeline
        //'code' is the bytecode representation of the glsl code - spirv 
        VkShaderModule VulkanShaderProgram::_createShaderModule(const std::vector<char>& code){
            VkShaderModuleCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            createInfo.codeSize = code.size();
            createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
            VkShaderModule shaderModule;
            if (vkCreateShaderModule(_logicalDevice, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
                CAST_ERROR("failed to create shader module!");
            }
            return shaderModule;
        }

        VkShaderModule VulkanShaderProgram::_createShaderModule(const std::vector<uint32_t>& code){
            VkShaderModuleCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
            createInfo.codeSize = code.size();
            createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
            VkShaderModule shaderModule;
            CAST_LOG("Defining module");
            if (vkCreateShaderModule(_logicalDevice, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
                CAST_ERROR("failed to create shader module!");
            }
            return shaderModule;
        }

}