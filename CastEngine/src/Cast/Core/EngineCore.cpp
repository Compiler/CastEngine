#include "EngineCore.h"

namespace Cast{


    void EngineCore::init(){
        switch(RenderContext::getAPI()){
            case RenderContext::API::OpenGL:{
                _window = new OpenGLWindow(1920, 1080, "Cast Engine");
                break;
            };
            default: CAST_FATAL("Window type not supported");
        }

    }

    void EngineCore::update(){



        _window->update();


    }

    void EngineCore::render(){


    }

    void EngineCore::destroy(){


    }

}