#pragma once
#include <Cast/Platform/OpenGL/OpenGLContext.h>
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/Rendering/Shader/OpenGLShaderProgram.h>

namespace Cast{

    class DebugScene{
        private:
            OpenGLShaderProgram _shader;
        public:
            void load();
            void update();
            void render();
            void unload();
    };

}