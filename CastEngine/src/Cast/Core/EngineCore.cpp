#include "EngineCore.h"

namespace Cast{

    void EngineCore::swapAPI(RenderContext::API newAPI){
        RenderContext::setAPI(newAPI);
        delete _renderer;
        _renderContext->Unload();
        delete _renderContext;
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

    void EngineCore::load(StartState state){

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        CAST_DEBUG("Vulkan Extensions supported: {}", extensionCount);



        CAST_DEBUG("Loading contexts");
        switch(state){
            case StartState::OpenGL:{
                RenderContext::setAPI(RenderContext::API::OpenGL);
                break;
            }
            case StartState::Vulkan:{
                RenderContext::setAPI(RenderContext::API::Vulkan);
                break;
            }
            default:{
                RenderContext::setAPI(RenderContext::API::OpenGL);
                break;
            }

        }

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
        if(InputManager::isKeyReleased(KeyCodes::KEY_SPACE)){
            CAST_LOG("XD");
            swapAPI(RenderContext::API::Vulkan);
        }
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