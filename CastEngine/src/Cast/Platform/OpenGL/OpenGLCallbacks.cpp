#include "OpenGLCallbacks.h"

namespace Cast{

    void OpenGLCallbacks::framebufferSizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    }

}