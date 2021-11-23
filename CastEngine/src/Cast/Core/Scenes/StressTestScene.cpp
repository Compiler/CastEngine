#include "StressTestScene.h"
#include <Cast/Core/Utils/MathUtils.h>
#include <glm/vec4.hpp>
#include <cmath>
namespace Cast{

    void StressTestScene::init(){
        static float MAX_CUBE_SIZE = 1;
        static float MIN_CUBE_SIZE = 0.1;
        glm::vec2 curCubeSize = {random_float(MIN_CUBE_SIZE, MAX_CUBE_SIZE), random_float(MIN_CUBE_SIZE, MAX_CUBE_SIZE)};
        float incremenet = 1;
        float range = 8;
        for(float x = -range; x <= range; x += incremenet){
            for(float z = -range; z <= range; z += incremenet){
                for(float y = 1; y <= 1; y += incremenet){
                    const auto entity = _registry.create();

                    TransformComponent& tComp = _registry.emplace<TransformComponent>(entity);
                    RenderableComponent& rComp = _registry.emplace<RenderableComponent>(entity);
                    CubeComponent& cComp = _registry.emplace<CubeComponent>(entity);
                    std::string name = "Cube" + std::to_string(NameComponent::count);
                    _registry.emplace<NameComponent>(entity, name);
                    
                    tComp.position = {x, -1, z, 1};
                    tComp.rotation = {0, 0, 0, 1};
                    tComp.scale = {1, 1, 1, 1};

                    rComp.color = glm::vec4(std::abs(x) / 16.0f, 0.2, 0.5, 1);
                    cComp.sideLength = incremenet - (0.45 * incremenet);
                }
            }
        }
        CAST_ERROR("Entity count = {} " , _registry.size());
        _renderer->CreateShader("blinn_phong", {{CAST_INTERNAL_SHADER("blinn_phong.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("blinn_phong.frag"), Shader::ShaderType::Fragment}});
        _renderer->CreateShader("passthrough_instanced", {{CAST_INTERNAL_SHADER("passthrough_instanced.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
    }
    void StressTestScene::load(){
        _renderer->CreateShader("blinn_phong", {{CAST_INTERNAL_SHADER("blinn_phong.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("blinn_phong.frag"), Shader::ShaderType::Fragment}});
        _renderer->CreateShader("passthrough_instanced", {{CAST_INTERNAL_SHADER("passthrough_instanced.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        _renderer->SetShader("passthrough_instanced");
        _renderer->SetShader("blinn_phong");
        CAST_DEBUG("Loaded shaders");

    }
    void StressTestScene::update(){
        for(auto &&[entity, transform, renderable, cube]: _registry.view<TransformComponent, RenderableComponent, CubeComponent>().each()) {
            float rand = Cast::random_float(0, 6);
            float speed = 1.5f;
            if(rand < 2){
                transform.rotation.z += speed;
            }else if(rand >= 2 && rand < 4){
                transform.rotation.y += speed;
            }else{
                transform.rotation.x += speed;
            }
        }
    }
    void StressTestScene::render(){
        
        _renderer->SubmitCube({0, 0, 0}, 0.1);
        _renderer->clearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a );
        _renderer->Draw(_registry);
    }
    void StressTestScene::unload(){
        CAST_WARN("StresTestScene Unloading!");
    }

}
