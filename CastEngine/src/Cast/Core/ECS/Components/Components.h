#pragma once
#include <glm/vec4.hpp>

namespace Cast{

    struct TransformComponent{
        
        glm::vec4 position{0};
        glm::vec4 rotation{0};
        glm::vec4 scale{0};

    };

    struct RenderableComponent{
        //enum {RightTriangle, Cube} Shape;
        glm::vec4 color;
    };

    struct CubeComponent{
        float sideLength = 1.0f;
    };
}