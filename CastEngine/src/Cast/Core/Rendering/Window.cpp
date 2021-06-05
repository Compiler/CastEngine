#include "Window.h"

namespace Cast{

    Window::Window(int width, int height){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        switch(RenderContext::getAPI()){
            case RenderContext::API::OpenGL:{
                glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
                break;
            };
            default: assert(false);//no other context supported

        }
        //#ifdef CAST_ENGINE_NAME
        //_window = glfwCreateWindow(width, height, CAST_ENGINE_NAME, 0, 0);
        //#else
        _window = glfwCreateWindow(width, height, "Cast Engine", 0, 0);
        //#endif
        

    }

}