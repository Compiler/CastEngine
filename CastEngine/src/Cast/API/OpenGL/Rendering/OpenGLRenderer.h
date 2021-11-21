#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/API/OpenGL/Rendering/Shading/OpenGLShaderProgram.h>
#include <Cast/Core/Rendering/Shapes/Cube.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexBuffer.h>
#include <Cast/API/OpenGL/Rendering/OpenGLVertexArray.h>
#include <Cast/Core/Rendering/Shader/UniformBufferObject.h>
#include <Cast/Core/Rendering/PerspectiveCamera.h>
#include <Cast/Core/Rendering/Camera.h>
#include <unordered_map>
#include <string>
#include <glm/glm.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace Cast{

    class OpenGLRenderer : public Renderer{
        private:
            Cast::VAOLayout _layout;
            OpenGLVertexArray _vao;
            OpenGLVertexBuffer<float> _buffer;
            std::unordered_map<std::string, OpenGLShaderProgram> _shaderMap;
            unsigned int _vaoID;
            unsigned int _uboBufferID;

        
        public:
            OpenGLRenderer();

            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            void SubmitVertexBuffer(const std::vector<VertexTemplate>& buffer);
            void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]);
            void SubmitTriangle(float bottomLeftX, float bottomLeftY, float size);
            void SubmitCube(glm::vec3 position, float side_len);

            void CreateShader(const char* name, std::initializer_list<Shader> shaders);
            //TODO: Error check so we dont null out on bad names
            OpenGLShaderProgram& GetShader(const char* name){return _shaderMap[std::string(name)];};
            void SetShader(const char* name){
                this->GetShader(name).use();
            };

            void Draw(entt::registry& registry);

            ~OpenGLRenderer();
    };

}