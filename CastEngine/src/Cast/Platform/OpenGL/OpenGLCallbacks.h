#pragma once
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Platform/OpenGL/OpenGLWindow.h>
#include <GLFW/glfw3.h>

namespace Cast{
    class OpenGLCallbacks{
        public:
            OpenGLCallbacks() = delete;
            static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
            static void windowResizeCallback(GLFWwindow *window, int width, int height);
    };
}