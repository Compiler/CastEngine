#pragma once
#define GLFW_INCLUDE_VULKAN
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Input/InputManager.h>
#include <Cast/Core/Components/Transform.h>
#include <Cast/Core/Scenes/DebugScene.h>

#include <Cast/API/OpenGL/Rendering/OpenGLContext.h>
#include <Cast/API/OpenGL/Rendering/OpenGLRenderer.h>

#include <Cast/API/Vulkan/Rendering/VulkanRenderer.h>
#include <Cast/API/Vulkan/Rendering/VulkanContext.h>
#include <Cast/Core/Rendering/Shader/ShaderParser.h>

namespace Cast{
    class EngineCore{
        private:
            Renderer* _renderer;
            RenderContext* _renderContext;
            DebugScene _scene{};
        public:
            enum StartState{ OpenGL = 0, Vulkan = 1 };
            void load(StartState state = StartState::Vulkan);
            void update();
            void render();
            void unload();
            inline bool closeRequested(){return _renderContext->getWindow()->shouldClose();}

    };


}