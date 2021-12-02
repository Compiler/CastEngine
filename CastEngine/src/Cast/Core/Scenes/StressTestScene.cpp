#include "StressTestScene.h"
#include <Cast/Core/Utils/MathUtils.h>
#include <glm/vec4.hpp>
#include <cmath>
namespace Cast{

    void StressTestScene::Initialize(){
        static float MAX_CUBE_SIZE = 1;
        static float MIN_CUBE_SIZE = 0.1;
        glm::vec2 curCubeSize = {random_float(MIN_CUBE_SIZE, MAX_CUBE_SIZE), random_float(MIN_CUBE_SIZE, MAX_CUBE_SIZE)};
        float incremenet = 1;
        float range = 8;
        for(float x = -range; x <= range; x += incremenet){
            for(float z = -range; z <= range; z += incremenet){
                for(float y = 1; y <= 1; y += incremenet){
                    const auto entity = m_registry.create();

                    TransformComponent& tComp = m_registry.emplace<TransformComponent>(entity);
                    RenderableComponent& rComp = m_registry.emplace<RenderableComponent>(entity);
                    CubeComponent& cComp = m_registry.emplace<CubeComponent>(entity);
                    std::string name = "Cube" + std::to_string(NameComponent::count);
                    m_registry.emplace<NameComponent>(entity, name);
                    
                    tComp.position = {x, -1, z, 1};
                    tComp.rotation = {0, 0, 0, 1};
                    tComp.scale = {1, 1, 1, 1};

                    rComp.color = glm::vec4(std::abs(x) / 16.0f, 0.2, 0.5, 1);
                    cComp.sideLength = incremenet - (0.45 * incremenet);
                }
            }
        }
        CAST_ERROR("Entity count = {} " , m_registry.size());
    }
    void StressTestScene::Load(){
        static bool initialize = true;
        if(initialize){initialize = false; Initialize();}
        m_renderer->CreateShader("blinn_phong", {{CAST_INTERNAL_SHADER("blinn_phong.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("blinn_phong.frag"), Shader::ShaderType::Fragment}});
        m_renderer->CreateShader("passthrough_instanced", {{CAST_INTERNAL_SHADER("passthrough_instanced.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        m_renderer->SetShader("passthrough_instanced");
        m_renderer->SetShader("blinn_phong");
        CAST_DEBUG("Loaded shaders");

    }
    void StressTestScene::Update(){
        for(auto &&[entity, transform, renderable, cube]: m_registry.view<TransformComponent, RenderableComponent, CubeComponent>().each()) {
            float rand = Cast::random_float(0, 6);
            float speed = 1.5f;
            if(rand < 2){
                transform.rotation.z += speed;
                transform.rotation.z = transform.rotation.z > 360 ? 0 : transform.rotation.z;
            }else if(rand >= 2 && rand < 4){
                transform.rotation.y += speed;
                transform.rotation.y = transform.rotation.y > 360 ? 0 : transform.rotation.y;
            }else{
                transform.rotation.x += speed;
                transform.rotation.x = transform.rotation.x > 360 ? 0 : transform.rotation.x;
            }
        }
    }
    void StressTestScene::Render(){
        
        m_renderer->SubmitCube({0, 0, 0}, 0.1);
        m_renderer->Draw(m_registry);
    }
    void StressTestScene::UnLoad(){
        m_registry.clear();
        _cubes.clear();
        CAST_WARN("StresTestScene Unloading!");
    }

}
