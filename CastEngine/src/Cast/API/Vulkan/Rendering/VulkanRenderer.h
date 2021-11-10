#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/API/Vulkan/Rendering/VulkanInstance.h>
namespace Cast{

    class VulkanRenderer : public Renderer{
        private:
            VulkanInstance* _instance;
        public:
            VulkanRenderer(VulkanInstance* instance);

            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]);
            void SubmitTriangle(float bottomLeftX, float bottomLeftY, float size);
            void Draw();

            void SetShader(const char* name, std::initializer_list<Shader> shaders);


            ShaderProgram* GetShader(const char* name){CAST_WARN("FUNCTION NOT IMPLEMENTED");};



            ~VulkanRenderer();
    };

}