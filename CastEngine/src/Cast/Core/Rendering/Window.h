#pragma once
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <GLFW\glfw3.h>
#include <Cast/Core/Rendering/RenderContext.h>

namespace Cast{

    class Window{

        public:
            Window(int width, int height);
            void destroy();

        private:
            GLFWwindow* _window;


    };

}