#include <stdio.h>
#include <Cast/Core/Debug/LoggingHeaderOnly.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Debug/LoggingUserFormatter.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <string.h>


int main(){
    CAST_LOG("glm::vec2 = {}\nglm::vec3 = {}\nglm::vec4 = {}\n", glm::vec2(1.2, 3.4), glm::vec3(1.2, 3.4, 5.6), glm::vec4(1.2, 3.4, 5.6, 7.8));
    CAST_DEBUG("CAST_DEBUG{}", 2);
    CAST_ERROR("CAST_ERROR");
    CAST_WARNING("CAST_WARNING");

}