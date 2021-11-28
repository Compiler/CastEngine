#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Cast/Core/Rendering/RenderContext.h>
#include <Cast/Core/GUI/MainGUi.h>
#include <Cast/API/Vulkan/Rendering/VulkanWindow.h>


#include <Cast/Vendor/ImGui/imgui_impl_opengl3.h>
#include <Cast/Vendor/ImGui/imgui_impl_glfw.h>


namespace Cast{

    class OpenGLContext : public Cast::RenderContext{

        public:
            OpenGLContext();
            

            void Load();
            void Update();
            void Render();
            void Unload();
            
            void LoadImGUI();
            void BeginGUI();
            void EndGUI();

    };


}