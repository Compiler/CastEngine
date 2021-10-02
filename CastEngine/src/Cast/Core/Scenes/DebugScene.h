#pragma once
#include <Cast/API/OpenGL/Rendering/OpenGLContext.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexArray.h>

#include <Cast/API/OpenGL/Rendering/OpenGLContext.h>
#include <Cast/API/OpenGL/Rendering/OpenGLRenderer.h>
namespace Cast{

    class DebugScene{
        private:
            Renderer* _renderer;

        public:
            void load();
            void update();
            void render();
            void unload();
            void setRenderer(Renderer* renderer){this->_renderer = renderer;}
    };

}