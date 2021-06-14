#include "EngineCore.h"

namespace Cast{


    void EngineCore::init(){
        switch(RenderContext::getAPI()){
            case RenderContext::API::OpenGL:{
                _renderContext = new OpenGLContext();
                CAST_DEBUG("Created OpenGL Context");
                break;
            };
            default: CAST_FATAL("Window type not supported");
        }

    }

    void EngineCore::update(){



        _renderContext->getWindow()->update();


    }

    void EngineCore::render(){

        _renderContext->clearColor(1.0, 0.0, 0.0, 1.0);
        _renderContext->clearColorBit();

    }

    void EngineCore::destroy(){


    }

}