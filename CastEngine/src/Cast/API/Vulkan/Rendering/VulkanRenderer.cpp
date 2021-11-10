#include "VulkanRenderer.h"

namespace Cast{
    
    VulkanRenderer::VulkanRenderer(VulkanInstance* instance){
        _instance = instance;

    }
    void VulkanRenderer::SetShader(const char* name, std::initializer_list<Shader> shaders){

        CAST_LOG("Setting shader to ");
        std::string shader_key = "";
        for(auto shader : shaders){
            CAST_LOG("{}", shader.filePath);
            shader_key += std::to_string((int)shader.type) + shader.filePath;
        }

        if(_shaderMap.find(shader_key) == _shaderMap.end()){
            CAST_LOG("New shader set, compiling and setting {}", shader_key);
            VulkanShaderProgram* program = new VulkanShaderProgram();
            for(auto shader : shaders){
                program->loadShader(shader.filePath, shader.type);
            }
            program->compile();
            _shaderMap.emplace(shader_key, program);
            _shaderMapNamed.emplace(name, shader_key);
            
        }
        CAST_LOG("Setting shader to ");
        for(auto shader : shaders){
            CAST_LOG("{}", shader.filePath);
        }
    }
    void VulkanRenderer::clearColor(float r, float g, float b, float a){
        
    }

    void VulkanRenderer::clearDepthBit(){}

    void VulkanRenderer::clearColorBit(){}

    void VulkanRenderer::SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]){
        VulkanInstance::vertices.push_back({glm::vec4(vertices[0].x, vertices[0].y, vertices[0].z, 1.0), glm::vec4(color[0].x, color[0].y, color[0].z, 1.0) });
    }
    void VulkanRenderer::SubmitTriangle(float bottomLeftX, float bottomLeftY, float size){
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX, bottomLeftY, 1, 1.0), glm::vec4(1,0,1,1) });
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX + size, bottomLeftY, 1, 1.0), glm::vec4(1,0,1,1) });
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX + size / 2.0, bottomLeftY + size, 1, 1.0), glm::vec4(1,0,1,1) });
    }
    void VulkanRenderer::Draw(){
        VulkanInstance::vertices.clear();
    }



    VulkanRenderer::~VulkanRenderer(){
        CAST_DEBUG("Vulkan Renderer unloading");
    }


}