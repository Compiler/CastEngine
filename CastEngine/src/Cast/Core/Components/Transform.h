#pragma once
#include <glm/vec3.hpp>
namespace Cast{
    
    union TransformComponent{
        struct {float x,y,z;} position_f, rotation_f, scale_f;
        glm::vec3 position, rotation, scale;
    };

}