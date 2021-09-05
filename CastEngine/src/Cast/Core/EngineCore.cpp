#include "EngineCore.h"

namespace Cast{


    void EngineCore::load(){
        CAST_DEBUG("Loading contexts");
        switch(RenderContext::GetAPI()){
            case RenderContext::API::OpenGL:{
                _renderer = new OpenGLRenderer();
                _renderContext = new OpenGLContext();
                CAST_DEBUG("Created OpenGL Context");
                break;
            };
            default: CAST_FATAL("Window type not supported");
        }
        CAST_DEBUG("Loading scene");
        _scene.load();
    }

    void EngineCore::update(){
        _scene.update();

        InputManager::clear();
        _renderContext->getWindow()->update();
    }

    void EngineCore::render(){

        _renderContext->clearColor(0.4, 0.4, 0.4, 1.0);
        _renderContext->clearColorBit();
        
        _scene.render();
        _renderContext->getWindow()->render();
    }

    void EngineCore::unload(){

        _scene.unload();
    }

}