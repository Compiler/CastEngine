#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/Rendering/Shader/OpenGLShaderProgram.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexArray.h>
namespace Cast{

    class OpenGLRenderer : public Renderer{
        private:
            OpenGLShaderProgram _shader;
            Cast::VAOLayout _layout;
            OpenGLVertexArray _vao;
            OpenGLVertexBuffer<float> _buffer;

        public:
            OpenGLRenderer();
            void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]);
            void Draw();
            void Flush();

    };

}