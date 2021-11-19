#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/API/OpenGL/OpenGLWindow.h>
#include <Cast/API/GLFW/GLFWInputKeyStore.h>
#include <Cast/Core/Input/InputManager.h>
#include <GLFW/glfw3.h>

namespace Cast{
    class OpenGLCallbacks{
        public:
            OpenGLCallbacks() = delete;
            static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
            static void windowResizeCallback(GLFWwindow *window, int width, int height);
    };
}