#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <Cast/Core/Rendering/Window.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/API/OpenGL/OpenGLCallbacks.h>
namespace Cast{

    class OpenGLWindow : public Cast::Window{

        public:
            OpenGLWindow(int width, int height, const char* windowName);
            void update();
            void render();
            void destroy();
            void setSize(int width, int height);
            void setPosition(int x, int y);

        
            inline bool shouldClose(){return glfwWindowShouldClose(_window);}
    };

//function for debugging opengl calls
#ifdef CAST_DEBUG_MODE
    inline void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id, GLenum severity, GLsizei length, const char *message, const void *userParam){
        // ignore non-significant error/warning codes
        if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return; 

        std::string info =  "\n-------------------------------\nDebug message (" + std::to_string(id) + "): " + message + "\n";
        switch (source)
        {
            case GL_DEBUG_SOURCE_API:             info += "Source: API\n"; break;
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   info += "Source: Window System\n"; break;
            case GL_DEBUG_SOURCE_SHADER_COMPILER: info += "Source: Shader Compiler\n"; break;
            case GL_DEBUG_SOURCE_THIRD_PARTY:     info += "Source: Third Party\n"; break;
            case GL_DEBUG_SOURCE_APPLICATION:     info += "Source: Application\n"; break;
            case GL_DEBUG_SOURCE_OTHER:           info += "Source: Other\n"; break;
        } 
        switch (type)
        {
            case GL_DEBUG_TYPE_ERROR:               info += "Type: Error\n"; break;
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: info += "Type: Deprecated Behaviour\n"; break;
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  info += "Type: Undefined Behaviour\n";break; 
            case GL_DEBUG_TYPE_PORTABILITY:         info += "Type: Portability\n"; break;
            case GL_DEBUG_TYPE_PERFORMANCE:         info += "Type: Performance\n"; break;
            case GL_DEBUG_TYPE_MARKER:              info += "Type: Marker\n"; break;
            case GL_DEBUG_TYPE_PUSH_GROUP:          info += "Type: Push Group\n"; break;
            case GL_DEBUG_TYPE_POP_GROUP:           info += "Type: Pop Group\n"; break;
            case GL_DEBUG_TYPE_OTHER:               info += "Type: Other\n"; break;
        } 
        
        switch (severity)
        {
            case GL_DEBUG_SEVERITY_HIGH:         info += "Severity: high\n"; break;
            case GL_DEBUG_SEVERITY_MEDIUM:       info += "Severity: medium\n"; break;
            case GL_DEBUG_SEVERITY_LOW:          info += "Severity: low\n"; break;
            case GL_DEBUG_SEVERITY_NOTIFICATION: info += "Severity: notification\n"; break;
        } 
        CAST_DEBUG("{}", info.c_str());
        
    }
#endif

}