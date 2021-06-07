#include "OpenGLCallbacks.h"

namespace Cast{

    void OpenGLCallbacks::framebufferSizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    }

    void OpenGLCallbacks::windowResizeCallback(GLFWwindow* window, int width, int height){
        Cast::OpenGLWindow* myWindow = reinterpret_cast<Cast::OpenGLWindow*>(glfwGetWindowUserPointer(window));
        myWindow->setSize(width, height);
    }



}