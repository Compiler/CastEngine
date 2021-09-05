#pragma once
#include <Cast/API/OpenGL/Rendering/OpenGLContext.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Rendering/Shader/OpenGLShaderProgram.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexArray.h>
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