#pragma once
#include <Cast/Core/Debug/Logger.h>
#include <Cast/API/OpenGL/OpenGLWindow.h>
#include <Cast/API/GLFW/GLFWInputKeyStore.h>
#include <Cast/Core/Input/InputManager.h>
#include <GLFW/glfw3.h>

namespace Cast{
    class WindowCallbacks{
        public:
            WindowCallbacks() = delete;
	        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
            static void mouseClickCallback(GLFWwindow* window, int button, int action, int mods);
            static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);
    };
}