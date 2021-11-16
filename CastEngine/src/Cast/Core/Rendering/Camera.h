#pragma once
#include <Cast/Core/Rendering/Shader/UniformBufferObject.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>

namespace Cast{


    class Camera{
        private:
            glm::vec3 cameraPos;
            glm::vec3 cameraTarget;
        public:
            UniformBufferObject ubo{};
            void update(){
                static auto startTime = std::chrono::high_resolution_clock::now();
                auto currentTime = std::chrono::high_resolution_clock::now();
                float time = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - startTime).count();
                ubo.model = glm::rotate(glm::mat4(1.0f), 0 * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
            }
            void init(float w, float h){

                ubo.model = glm::rotate(glm::mat4(1.0f), 1 * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 0.0f));
                ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, -5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
                ubo.proj = glm::perspective(glm::radians(45.0f), w / h, 0.1f, 10.0f);
                ubo.proj[1][1] *= -1;
            }
    };

}