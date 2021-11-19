#include "EngineCore.h"

namespace Cast{

    void EngineCore::swapAPI(RenderContext::API newAPI){
        RenderContext::setAPI(newAPI);
        CAST_WARN("UNloading Current API");
        switch(RenderContext::GetAPI()){
            case RenderContext::API::OpenGL:{
                _renderer = _openglRenderer;
                _renderContext = _openglRenderContext;
                CAST_DEBUG("Created OpenGL Context");
                break;
            };
            case RenderContext::API::Vulkan:{
                _renderer = _vulkanRenderer;
                _renderContext = _vulkanRenderContext;
                CAST_DEBUG("Created Vulkan Context");
                break;
            };
            default: CAST_FATAL("Window type not supported");
        }
        _stressScene.setRenderer(_renderer);
        _stressScene.load();
    }

    void EngineCore::load(StartState state){

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        CAST_DEBUG("Vulkan Extensions supported: {}", extensionCount);

        CAST_DEBUG("Loading renderers");
        
        _openglRenderContext = new OpenGLContext();
        _openglRenderContext->Load();
        _openglRenderer = new OpenGLRenderer();
        CAST_LOG("Loading Vulkan");
        _vulkanRenderContext = new VulkanContext();
        _vulkanRenderContext->Load();
        _vulkanRenderer = new VulkanRenderer(_vulkanRenderContext->getVulkanInstance());

        CAST_DEBUG("Loading contexts");
        switch(state){
            case StartState::OpenGL:{
                swapAPI(RenderContext::API::OpenGL);
                break;
            }
            case StartState::Vulkan:{
                swapAPI(RenderContext::API::Vulkan);
                break;
            }
            default:{
                swapAPI(RenderContext::API::OpenGL);
                break;
            }

        }
        _stressScene.load();


    }

    void EngineCore::update(){
        // _stressScene.update();
        // _renderContext->Update();
        InputManager::clear();
        if(InputManager::isKeyReleased(KeyCodes::KEY_ESCAPE)) this->_renderContext->getWindow()->destroy();
        if(InputManager::isKeyReleased(KeyCodes::KEY_SPACE)){
            CAST_WARN("Swapping API");
            if(RenderContext::GetAPI() == RenderContext::API::Vulkan)
                swapAPI(RenderContext::API::OpenGL);
            else
                swapAPI(RenderContext::API::Vulkan);
        }
    }

    void EngineCore::render(){

        // _renderContext->Render();
        // _renderContext->getWindow()->render();
        // _stressScene.render();
    }

    void EngineCore::unload(){
        _renderContext->Unload();

        //_scene.unload();
    }

}