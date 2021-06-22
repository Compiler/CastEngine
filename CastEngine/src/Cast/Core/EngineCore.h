#pragma once
#include <Cast/Platform/OpenGL/OpenGLContext.h>
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/Input/InputManager.h>
#include <Cast/Core/Components/Transform.h>
#include <Cast/Core/Utils/DebugScene.h>
namespace Cast{

    class EngineCore{
        private:
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