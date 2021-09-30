#pragma once
#include <Cast/Core/Rendering/RenderContext.h>
#include <Cast/API/Vulkan/Rendering/VulkanInstance.h>
#include <Cast/API/Vulkan/Rendering/VulkanWindow.h>
namespace Cast{

    class VulkanContext : public Cast::RenderContext{
        private:
            VulkanInstance _vulkanInstance;
        public:
            VulkanContext();

            
            void Load();
            void Update();
            void Render();
            void Unload();
            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            

    };


}