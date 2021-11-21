#pragma once
#include <glm/vec4.hpp>

namespace Cast{

    struct TransformComponent{
        
        glm::vec4 position;
        glm::vec4 rotation;
        glm::vec4 scale;

    };

    struct RenderableComponent{
        //enum {RightTriangle, Cube} Shape;
        glm::vec4 color;
    };
}