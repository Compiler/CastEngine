#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/API/Vulkan/Rendering/VulkanInstance.h>
#include <Cast/API/Vulkan/Rendering/GraphicsPipeline.h>
namespace Cast{
    class VulkanRenderer : public Renderer{
        private:
            VulkanInstance* _instance;
            std::unordered_map<std::string, GraphicsPipeline> _graphicsPipelineMap;

        public:
            VulkanRenderer(VulkanInstance* instance);

            void clearColor(float r, float g, float b, float a);
            void clearDepthBit();
            void clearColorBit();

            void SubmitTriangle(glm::vec3 vertices[3], glm::vec3 color[3]);
            void SubmitTriangle(float bottomLeftX, float bottomLeftY, float size);

            void SubmitCube(glm::vec3 position, float side_len);

            void Draw();

            void CreateShader(const char* name, std::initializer_list<Shader> shaders);
            void SetShader(const char* name);

            //TODO: Error check so we dont null out on bad names
            ShaderProgram& GetShader(const char* name){return _graphicsPipelineMap[std::string(name)].getShaderProgram();};



            ~VulkanRenderer();
    };

}