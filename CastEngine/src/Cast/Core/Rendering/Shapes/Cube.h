#pragma once
#include <Cast/Core/Rendering/Shapes/Shape.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace Cast{

    class Cube : public Shape{

        private:
            glm::vec4 _center;
            float _sideLength;

        public:
            Cube();
            Cube(glm::vec3 center, float sideLen);
            Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis);

            Cube(glm::vec4 color);
            Cube(glm::vec3 center, float sideLen, glm::vec4 color);
            Cube(glm::vec3 center, float sideLen, float rotation, glm::vec3 axis, glm::vec4 color);
            
            void Load();


    };


}