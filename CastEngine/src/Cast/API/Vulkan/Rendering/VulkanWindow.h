#pragma once
#include <string>
#include <Cast/Core/Rendering/Window.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/API/OpenGL/OpenGLCallbacks.h>
namespace Cast{

    class VulkanWindow : public Cast::Window{

        public:
            VulkanWindow(int width, int height, const char* windowName);
            void update();
            void render();
            void destroy();
            void setSize(int width, int height);
            void setPosition(int x, int y);

        
            inline bool shouldClose(){return glfwWindowShouldClose(_window);}
    };
}