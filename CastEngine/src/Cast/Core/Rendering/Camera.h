#pragma once
#include <Cast/Core/Rendering/Shader/UniformBufferObject.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <chrono>

namespace Cast{


    class Camera{

        public:
            UniformBufferObject ubo{};
            void init(float w, float h){

                ubo.model = glm::rotate(glm::mat4(1.0f), 1 * glm::radians(90.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                ubo.view = glm::lookAt(glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                ubo.proj = glm::perspective(glm::radians(45.0f), w / h, 0.1f, 10.0f);
                ubo.proj[1][1] *= -1;
            }
    };

}