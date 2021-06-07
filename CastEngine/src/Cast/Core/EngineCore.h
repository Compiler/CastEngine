#pragma once
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Platform/OpenGL/OpenGLWindow.h>
namespace Cast{

    class EngineCore{
        private:
            Window* _window;

        public:
            void init();
            void update();
            void render();
            void destroy();
            inline bool closeRequested(){return _window->shouldClose();}

    };


}