#include "StressTestScene.h"
#include <Cast/Core/Utils/MathUtils.h>
#include <glm/vec4.hpp>
namespace Cast{

    void StressTestScene::load(){
        _renderer->CreateShader("blinn_phong", {{CAST_INTERNAL_SHADER("blinn_phong.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("blinn_phong.frag"), Shader::ShaderType::Fragment}});

        _renderer->CreateShader("passthrough_instanced", {{CAST_INTERNAL_SHADER("passthrough_instanced.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        _renderer->SetShader("passthrough_instanced");
        _renderer->SetShader("blinn_phong");
        CAST_DEBUG("Loaded shaders");

        static float MAX_CUBE_SIZE = 1;
        static float MIN_CUBE_SIZE = 0.1;
        glm::vec2 curCubeSize = {random_float(MIN_CUBE_SIZE, MAX_CUBE_SIZE), random_float(MIN_CUBE_SIZE, MAX_CUBE_SIZE)};
        _cubes = {};
        float incremenet = 0.175;
        float range = 8;
        for(float x = -range; x <= range; x += incremenet){
            for(float z = -range; z <= range; z += incremenet){
                for(float y = 1; y <= 1; y += incremenet){
                    _cubes.push_back(Cube{{x, 0, z}, incremenet - (0.25 * incremenet)});
                }
            }
        }

    }
    void StressTestScene::update(){}
    void StressTestScene::render(){
       

        for(auto& cube : _cubes){
            //cube.Rotate(1, glm::vec3(0,0,1));
            //cube.Load();
            //_renderer->SubmitVertexBuffer(cube.getRendererVertices());
        }
        _renderer->SubmitVertexBuffer(_cubes[0].getRendererVertices());

        _renderer->clearColor(0.1f, 0.1f, 0.15f, 1.0f);
        
        _renderer->Draw();
    }
    void StressTestScene::unload(){
        CAST_WARN("StresTestScene Unloading!");
    }

}
