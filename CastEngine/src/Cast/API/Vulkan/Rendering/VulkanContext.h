#pragma once
#include <Cast/Core/Rendering/RenderContext.h>
#include <Cast/API/Vulkan/Rendering/VulkanInstance.h>
#include <Cast/API/Vulkan/Rendering/VulkanWindow.h>

#include <Cast/Vendor/ImGui/imgui_impl_vulkan.h>
#include <Cast/Vendor/ImGui/imgui_impl_glfw.h>
#include <Cast/Vendor/ImGui/imgui.h>
namespace Cast{

    class VulkanContext : public Cast::RenderContext{
        private:
            VulkanInstance* _vulkanInstance;
        public:
            VulkanContext();

            
            void Load();
            void Update();
            void Render();
            void Unload();
            
            void LoadImGUI();
            void RenderImGUI();
            

            VulkanInstance* getVulkanInstance(){return this->_vulkanInstance;}

            

    };


}