#include "OpenGLCallbacks.h"

namespace Cast{

    void OpenGLCallbacks::framebufferSizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    }

    void OpenGLCallbacks::windowResizeCallback(GLFWwindow* window, int width, int height){
        Cast::Window* myWindow = reinterpret_cast<Cast::Window*>(glfwGetWindowUserPointer(window));
        glViewport(0, 0, width, height);
        myWindow->setSize(width, height);
    }


}