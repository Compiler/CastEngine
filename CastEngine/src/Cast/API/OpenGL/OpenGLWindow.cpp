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
        m_window = glfwCreateWindow(width, height, windowName, 0, 0);
        glfwSetWindowPos(m_window, 1920, 0);
        CAST_DEBUG("GLFWWindow Context created");

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, reinterpret_cast<void*>(this));

        glfwSetFramebufferSizeCallback(m_window, OpenGLCallbacks::framebufferSizeCallback);  
        glfwSetWindowSizeCallback(m_window, OpenGLCallbacks::windowResizeCallback);
        glfwSetKeyCallback(m_window, WindowCallbacks::keyCallback);
        glfwSetMouseButtonCallback(m_window, WindowCallbacks::mouseClickCallback);
        glfwSetCursorPosCallback(m_window, WindowCallbacks::cursorPositionCallback);
        CAST_DEBUG("Created OpenGL Window.");

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            CAST_FATAL("Failed to initialize GLAD");
        }   

        
        #ifdef CAST_DEBUG_MODE
            int flags; glGetIntegerv(GL_CONTEXT_FLAGS, &flags);
            if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
            {
                glEnable(GL_DEBUG_OUTPUT);
                glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); 
                glDebugMessageCallback(glDebugOutput, nullptr);
                glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE); 
            }
        #else
            CAST_LOG("Cast not in debug mode");
        #endif



    }




}