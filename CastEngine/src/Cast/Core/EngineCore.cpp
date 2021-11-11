#include "EngineCore.h"

namespace Cast{


    void EngineCore::load(){

        //ShaderParser::compileGLSLToSPRV(CAST_INTERNAL_SHADER("passthrough.vert"), CAST_INTERNAL_SHADER("realtime_comp.spv"), Shader::ShaderType::Vertex);
        


        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        CAST_DEBUG("Vulkan Extensions supported: {}", extensionCount);



        CAST_DEBUG("Loading contexts");
        RenderContext::setAPI(RenderContext::API::Vulkan);
        switch(RenderContext::GetAPI()){
            case RenderContext::API::OpenGL:{
                _renderer = new OpenGLRenderer();
                _renderContext = new OpenGLContext();
                _renderContext->Load();
                CAST_DEBUG("Created OpenGL Context");
                break;
            };
            case RenderContext::API::Vulkan:{
                _renderContext = new VulkanContext();
                _renderContext->Load();
                _renderer = new VulkanRenderer(static_cast<VulkanContext*>(_renderContext)->getVulkanInstance());
                CAST_DEBUG("Created Vulkan Context");
                break;
            };
            default: CAST_FATAL("Window type not supported");
        }
        CAST_DEBUG("Loading scene");
        _scene.setRenderer(_renderer);
        _scene.load();
    }

    void EngineCore::update(){
        _scene.update();
        InputManager::clear();
        _renderContext->Update();
    }

    void EngineCore::render(){

        _renderer->clearColor(0.4, 0.4, 0.4, 1.0);
        _renderer->clearColorBit();
        
        _scene.render();
        _renderContext->Render();
        _renderContext->getWindow()->render();
    }

    void EngineCore::unload(){
        _renderContext->Unload();

        //_scene.unload();
    }

}