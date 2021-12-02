#pragma once
#define GLFW_INCLUDE_VULKAN
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Input/InputManager.h>
#include <Cast/Core/Scenes/DebugScene.h>
#include <Cast/Core/Scenes/StressTestScene.h>

#include <Cast/API/OpenGL/Rendering/OpenGLContext.h>
#include <Cast/API/OpenGL/Rendering/OpenGLRenderer.h>

#include <Cast/API/Vulkan/Rendering/VulkanRenderer.h>
#include <Cast/API/Vulkan/Rendering/VulkanContext.h>
#include <Cast/Core/Rendering/Shader/ShaderParser.h>

#include <Cast/Core/GUI/MainGUI.h>

#include <Cast/Core/Scenes/SceneManager.h>
namespace Cast{
    class EngineCore{
        friend class Entry;
        private:
            MainGUI _gui;
            Renderer* _renderer;
            VulkanRenderer* _vulkanRenderer;
            OpenGLRenderer* _openglRenderer;

            RenderContext* _renderContext;
            VulkanContext* _vulkanRenderContext;
            OpenGLContext* _openglRenderContext;

            SceneManager _sceneManager{};

            RenderContext::API _activeAPI;
            bool _runStressTest = false;
        public:
            enum class StartState{ OpenGL = 0, Vulkan = 1 };
            void load(StartState state = StartState::Vulkan);
            void update();
            void render();
            void unload();

            void swapAPI(RenderContext::API newAPI);
            inline bool closeRequested(){return _renderContext->getWindow()->shouldClose();}

    };


}