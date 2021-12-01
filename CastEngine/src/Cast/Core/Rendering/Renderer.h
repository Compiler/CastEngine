#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <vector>
#include <Cast/Core/Rendering/RenderContext.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/Core/Rendering/Shader/Shader.h>
#include <Cast/Core/Rendering/Shader/ShaderProgram.h>

#include <Cast/Vendor/entt/entity/registry.hpp>
#include <Cast/Core/ECS/Components/Components.h>

#include <Cast/Core/Rendering/PerspectiveCamera.h>
namespace Cast{


    struct VertexTemplate{  
        glm::vec4 position;
        glm::vec4 color;
        glm::vec4 normal;
        glm::mat4 model;


    };

    


    class Renderer{
        protected:

            std::vector<float> m_vertices;
            int m_currentAliveVertices;
            int m_offsetToAliveVertices;
            glm::vec4 m_curColor = {0.5, 0.5, 0.5, 1.0};
            //these are runtime constants because of glm
            const glm::vec4 DEFAULT_NORMAL = {0, 0, 1, 1};      //TODO Delete this, make it relative to the cameras look position
            const glm::mat4 DEFAULT_MODEL = glm::mat4{1};       //TODO Delete this 


            PerspectiveCamera m_camera;

        public:
            static int MAX_VERTICES;
            Renderer():m_currentAliveVertices(0),m_offsetToAliveVertices(0){}
            virtual void clearColor(float r, float g, float b, float a) = 0;
            virtual void clearDepthBit() = 0;
            virtual void clearColorBit() = 0;
            virtual void SubmitVertexBuffer(const std::vector<VertexTemplate>& buffer) = 0;
            virtual void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]) = 0;
            virtual void SubmitTriangle(float bottomLeftX, float bottomLeftY, float size) = 0;
            virtual void SubmitCube(glm::vec3 position, float side_len) = 0;
            virtual void Draw(entt::registry& registry) = 0;
            virtual void CreateShader(const char* name, std::initializer_list<Shader> shaders) = 0;
            virtual void SetShader(const char* name) = 0;
            virtual ShaderProgram& GetShader(const char* name) = 0;
            virtual ~Renderer(){}

            void SetColor(glm::vec4& col){this->m_curColor = col;}
            void SetColor(glm::vec4 col){this->m_curColor = col;}
            PerspectiveCamera& getCamera(){return this->m_camera;}
            static RenderContext::API GetAPI(){return RenderContext::GetAPI();}

    };

}