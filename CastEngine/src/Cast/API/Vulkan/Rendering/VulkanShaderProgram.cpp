#include "VulkanShaderProgram.h"

namespace Cast{
    
        VulkanShaderProgram::VulkanShaderProgram(const char* vertFilePath, const char* fragFilePath){
            load(vertFilePath, fragFilePath);
            _isSet = true;
        }

        void VulkanShaderProgram::loadShader(const char* shaderFilePath, Shader::ShaderType shaderType){
            std::string shader_out_path = std::string(shaderFilePath) + ".spv";
            auto shader_spv_format = ShaderParser::compileGLSLToSPRV(shaderFilePath, shader_out_path.c_str(), shaderType);
            if(shader_spv_format.empty()){
                CAST_FATAL("Shader '{}' couldnt not be compiled.", shaderFilePath);
            }

            // VkShaderModule shader_module = _createShaderModule(_logicalDevice, shader_spv_format);
            // VkShaderStageFlagBits shader_bit = _getShaderBitFromType(shaderType);
            // VkPipelineShaderStageCreateInfo shaderStageInfo{};
            // shaderStageInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            // shaderStageInfo.stage = shader_bit;
            // shaderStageInfo.module = shader_module;
            // shaderStageInfo.pName = "main";

            //_shaderCreationData.push_back({shaderStageInfo, shader_module});
        }
        void VulkanShaderProgram::loadShader(std::initializer_list<Shader> shaders){
            for(const auto& shader : shaders)loadShader(shader.filePath, shader.type);
        }

        PipeLineShaderInfo VulkanShaderProgram::load(const char* vertFilePath, const char* fragFilePath){
            //TODO Compile shaders to spv if they arent in that format
            // std::string vertexFilePath = vertFilePath;
            // if(vertexFilePath.substr(vertexFilePath.find_last_of(".")) != "spv"){
            //     CAST_DEBUG("'{}' is not a spv file, attempting to compile to spv...");
            // }

            
            //auto vertShaderCode = Cast::FileLoaderFactory::readSPV(vertFilePath);
            //auto fragShaderCode = Cast::FileLoaderFactory::readSPV(fragFilePath);
            std::string vert_out_path = std::string(vertFilePath) + ".spv";
            std::string frag_out_path = std::string(fragFilePath) + ".spv";
            auto vertShaderCode = Cast::ShaderParser::compileGLSLToSPRV(vertFilePath, vert_out_path.c_str(), Shader::ShaderType::Vertex);
            auto fragShaderCode = Cast::ShaderParser::compileGLSLToSPRV(fragFilePath, frag_out_path.c_str(), Shader::ShaderType::Fragment);


            VkShaderModule vertShaderModule = _createShaderModule(vertShaderCode);
            VkShaderModule fragShaderModule = _createShaderModule(fragShaderCode);

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
            _isSet = true;
            return _pipelineData;
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
            if (vkCreateShaderModule(_logicalDevice, &createInfo, nullptr, &shaderModule) != VK_SUCCESS) {
                CAST_ERROR("failed to create shader module!");
            }
            return shaderModule;
        }

}