#pragma once
#include <Cast/Core/Rendering/Window.h>
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Platform/OpenGL/OpenGLCallbacks.h>
namespace Cast{

    class OpenGLWindow : public Cast::Window{
        private:
            GLFWwindow* _window;

        public:
            OpenGLWindow(int width, int height, const char* windowName);
            void update();
            void destroy();
        
            inline bool shouldClose(){return glfwWindowShouldClose(_window);}
    };

}