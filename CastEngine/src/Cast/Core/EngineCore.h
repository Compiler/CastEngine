#pragma once
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Platform/OpenGL/OpenGLContext.h>
#include <Cast/Core/Input/InputManager.h>
namespace Cast{

    class EngineCore{
        private:
            RenderContext* _renderContext;

        public:
            void init();
            void update();
            void render();
            void destroy();
            inline bool closeRequested(){return _renderContext->getWindow()->shouldClose();}

    };


}