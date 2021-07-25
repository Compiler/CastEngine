#pragma once
#include <Cast/Platform/OpenGL/Rendering/OpenGLContext.h>
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/Input/InputManager.h>
#include <Cast/Core/Components/Transform.h>
#include <Cast/Core/Scenes/DebugScene.h>
#include <Cast/Platform/OpenGL/Rendering/OpenGLRenderer.h>
namespace Cast{

    class EngineCore{
        private:
            Renderer* _renderer;
            RenderContext* _renderContext;
            DebugScene _scene{};
        public:
            void load();
            void update();
            void render();
            void unload();
            inline bool closeRequested(){return _renderContext->getWindow()->shouldClose();}

    };


}