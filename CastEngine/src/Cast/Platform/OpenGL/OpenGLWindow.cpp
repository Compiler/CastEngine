#include "OpenGLWindow.h"

namespace Cast{

    OpenGLWindow::OpenGLWindow(int width, int height, const char* windowName): Cast::Window(width, height, windowName){
        glfwInit();
        CAST_DEBUG("Init glfw");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SAMPLES, 4);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
        CAST_DEBUG("GLFWWindowHints enabled");
        #ifdef CAST_DEBUG_MODE
            CAST_DEBUG("Enabling Debug Context");
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
        #else
            CAST_LOG("Cast not in debug mode");
        #endif

        CAST_LOG("Creating window");
        _window = glfwCreateWindow(width, height, windowName, 0, 0);
        CAST_DEBUG("GLFWWindow Context created");

        glfwMakeContextCurrent(_window);
        glfwSetWindowUserPointer(_window, reinterpret_cast<void*>(this));

        glfwSetFramebufferSizeCallback(_window, OpenGLCallbacks::framebufferSizeCallback);  
        glfwSetWindowSizeCallback(_window, OpenGLCallbacks::windowResizeCallback);
        glfwSetKeyCallback(_window, OpenGLCallbacks::keyCallback);
        glfwSetMouseButtonCallback(_window, OpenGLCallbacks::mouseClickCallback);
        glfwSetCursorPosCallback(_window, OpenGLCallbacks::cursorPositionCallback);
        CAST_DEBUG("Created OpenGL Window.");

    }


    void OpenGLWindow::update(){
        glfwPollEvents();    
    }
    void OpenGLWindow::render(){
        glfwSwapBuffers(_window);
    }
    void OpenGLWindow::destroy(){
        CAST_WARN("Destroying OpenGLWindow");
        glfwTerminate();
    }



    void OpenGLWindow::setSize(int width, int height){
        m_width = width;
        m_height = height;
        glfwSetWindowSize(_window, m_width, m_height);
    }

    void OpenGLWindow::setPosition(int x, int y){
        glfwSetWindowPos(_window, x, y);
    }



}