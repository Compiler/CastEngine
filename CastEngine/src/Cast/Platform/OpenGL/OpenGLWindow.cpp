#include "OpenGLWindow.h"

namespace Cast{

    OpenGLWindow::OpenGLWindow(int width, int height, const char* windowName): Cast::Window(width, height, windowName){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        _window = glfwCreateWindow(width, height, windowName, 0, 0);
        
        glfwSetWindowUserPointer(_window, reinterpret_cast<void*>(this));

        glfwSetFramebufferSizeCallback(_window, OpenGLCallbacks::framebufferSizeCallback);  
    }


    void OpenGLWindow::update(){
        glfwSwapBuffers(_window);
        glfwPollEvents();    
    }
    void OpenGLWindow::destroy(){
        CAST_WARN("Destroying OpenGLWindow");
        glfwTerminate();
    }


}