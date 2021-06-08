#pragma once
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Platform/OpenGL/OpenGLWindow.h>
#include <Cast/Platform/OpenGL/OpenGLContext.h>
namespace Cast{

    class EngineCore{
        private:
            Window* _window;
            RenderContext* _renderContext;

        public:
            void init();
            void update();
            void render();
            void destroy();
            inline bool closeRequested(){return _window->shouldClose();}

    };


}