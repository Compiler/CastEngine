#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexArray.h>
#include <unordered_map>
#include <string>
namespace Cast{

    class OpenGLRenderer : public Renderer{
        private:
            Cast::VAOLayout _layout;
            OpenGLVertexArray _vao;
            OpenGLVertexBuffer<float> _buffer;
            std::unordered_map<std::string, OpenGLShaderProgram> _shaderMap;


        public:
            OpenGLRenderer();

            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]);
            void SubmitTriangle(float bottomLeftX, float bottomLeftY, float size);

            void SetShader(std::initializer_list<Shader> shaders);
            void Draw();

            ~OpenGLRenderer();
    };

}