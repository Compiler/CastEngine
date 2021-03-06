#include "VulkanRenderer.h"

namespace Cast{
    
    VulkanRenderer::VulkanRenderer(VulkanInstance* instance){
        _instance = instance;
        _graphicsPipelineMap.emplace("Default", _instance->createDefaultPipeline());
        _instance->_pipeline = &_graphicsPipelineMap["Default"];
        _instance->_createGraphicsCommandBuffers();

    }
    void VulkanRenderer::SetShader(const char* name){
        if(_graphicsPipelineMap.find(name) != _graphicsPipelineMap.end()){
            _instance->_pipeline = &_graphicsPipelineMap[name];
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
        _instance->_clearColor = {r, g, b, a};
    }

    void VulkanRenderer::clearDepthBit(){}

    void VulkanRenderer::clearColorBit(){}

    /** DRAW API **/


    void VulkanRenderer::SubmitVertexBuffer(const std::vector<VertexTemplate>& buffer){
        VulkanInstance::vertices.insert(VulkanInstance::vertices.end(), buffer.begin(), buffer.end());
    }

    void VulkanRenderer::SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]){
        //VulkanInstance::vertices.push_back({glm::vec4(vertices[0].x, vertices[0].y, vertices[0].z, 1.0), glm::vec4(color[0].x, color[0].y, color[0].z, 1.0)});
    }
    void VulkanRenderer::SubmitTriangle(float bottomLeftX, float bottomLeftY, float size){
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX + size / 2.0, bottomLeftY + size, 1, 1.0), m_curColor, DEFAULT_NORMAL, DEFAULT_MODEL});
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX + size, bottomLeftY, 1, 1.0), m_curColor, DEFAULT_NORMAL, DEFAULT_MODEL});
        VulkanInstance::vertices.push_back({glm::vec4(bottomLeftX, bottomLeftY, 1, 1.0), m_curColor, DEFAULT_NORMAL, DEFAULT_MODEL});


    }
    void VulkanRenderer::SubmitCube(glm::vec3 position, float side_len){
        Cast::Cube cube{position, side_len, m_curColor};
        SubmitVertexBuffer(cube.getRendererVertices());
    }

    void VulkanRenderer::Draw(entt::registry& registry){
        for(auto &&[entity, transform, renderable, cube]: registry.view<TransformComponent, RenderableComponent, CubeComponent>().each()) {
            SubmitVertexBuffer(Cube{transform.position, cube.sideLength, transform.rotation, transform.scale, renderable.color}.getRendererVertices());
        }
        _instance->_createVertexBuffers();
        _instance->_createGraphicsCommandBuffers();//this is our draw call...
        VulkanInstance::vertices.clear();
    }



    VulkanRenderer::~VulkanRenderer(){
        CAST_DEBUG("Vulkan Renderer unloading");
    }


}