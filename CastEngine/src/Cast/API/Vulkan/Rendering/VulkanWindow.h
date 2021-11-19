#pragma once
#include <string>
#include <Cast/Core/Rendering/Window.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Rendering/WindowCallbacks.h>
namespace Cast{

    class VulkanWindow : public Cast::Window{

        public:
            VulkanWindow(int width, int height, const char* windowName);

        
    };
}