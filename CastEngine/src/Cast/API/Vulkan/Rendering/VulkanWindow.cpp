#include "VulkanWindow.h"

namespace Cast{
    VulkanWindow::VulkanWindow(int width, int height, const char* windowName): Cast::Window(width, height, windowName){
        glfwInit();
        CAST_DEBUG("Init glfw");
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_SAMPLES, 4);
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

        CAST_DEBUG("Created Vulkan Window.");

        
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


    void VulkanWindow::update(){
        glfwPollEvents();    
    }
    void VulkanWindow::render(){
        glfwSwapBuffers(_window);
    }
    void VulkanWindow::destroy(){
        CAST_WARN("Destroying VulkanWindow");
        glfwTerminate();
    }



    void VulkanWindow::setSize(int width, int height){
        m_width = width;
        m_height = height;
        glfwSetWindowSize(_window, m_width, m_height);
    }

    void VulkanWindow::setPosition(int x, int y){
        glfwSetWindowPos(_window, x, y);
    }
}