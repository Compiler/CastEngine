#pragma once

namespace Cast{

    struct Shader{
        enum class ShaderType{
            None = 0, Vertex = 1, Tesselation = 2, Geometry = 3, Fragment = 4
        };
        const char* filePath;
        ShaderType type;


    };
}