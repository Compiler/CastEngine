#include "VulkanWindow.h"

namespace Cast{
    VulkanWindow::VulkanWindow(int width, int height, const char* windowName): Cast::Window(width, height, windowName){
        glfwInit();
        CAST_DEBUG("Init glfw");
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        CAST_DEBUG("GLFWWindowHints enabled");
        #ifdef CAST_DEBUG_MODE
            CAST_DEBUG("Enabling Debug Context");
            glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
        #else
            CAST_LOG("Cast not in debug mode");
        #endif

        CAST_LOG("Creating window");
        m_window = glfwCreateWindow(width, height, windowName, 0, 0);
        CAST_DEBUG("GLFWWindow Context created");

        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, reinterpret_cast<void*>(this));
        glfwSetKeyCallback(m_window, WindowCallbacks::keyCallback);

        CAST_DEBUG("Created Vulkan Window.");

        
        #ifdef CAST_DEBUG_MODE
            
        #else
            CAST_LOG("Cast not in debug mode");
        #endif




    }



}