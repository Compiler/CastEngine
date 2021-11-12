#include "VulkanRenderer.h"

namespace Cast{
    
    VulkanRenderer::VulkanRenderer(VulkanInstance* instance){
        _instance = instance;
        _graphicsPipelineMap.emplace("Default", _instance->createDefaultPipeline());
        _instance->_graphicsPipeline = _graphicsPipelineMap["Default"].getPipeline();
        _instance->_createGraphicsCommandBuffers();

    }
    void VulkanRenderer::SetShader(const char* name){
        if(_graphicsPipelineMap.find(name) != _graphicsPipelineMap.end()){
            _instance->_graphicsPipeline = _graphicsPipelineMap[name].getPipeline();
            _instance->_createGraphicsCommandBuffers();
        }else{
            CAST_WARN("No shader by name '{}' found!", name);
        }
    }
    void VulkanRenderer::CreateShader(const char* name, std::initializer_list<Shader> shaders){

        if(_graphicsPipelineMap.find(name) == _graphicsPipelineMap.end()){
            CAST_LOG("no graphics pipeline set for the name '{}', creating new one", name);
            VulkanShaderProgram program = VulkanShaderProgram(_instance->_logicalDevice);
            program.loadShader(shaders);
            program.compile();
            GraphicsPipeline pipe{_instance->_logicalDevice, name, program, _instance->_swapChainExtent, _instance->_renderPass};
            _graphicsPipelineMap.emplace(name, pipe);
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
        _instance->_createVertexBuffers();
        _instance->_createGraphicsCommandBuffers();
        _instance->_createSyncObjects();
        VulkanInstance::vertices.clear();
    }



    VulkanRenderer::~VulkanRenderer(){
        CAST_DEBUG("Vulkan Renderer unloading");
    }


}