#include "DebugScene.h"
#include <glm/vec4.hpp>
namespace Cast{

    void DebugScene::load(){
        _renderer->CreateShader("passthrough", {{CAST_INTERNAL_SHADER("passthrough_vert.spv"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough_frag.spv"), Shader::ShaderType::Fragment}});
        _renderer->CreateShader("red", {{CAST_INTERNAL_SHADER("realtime_comp.spv"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("red_frag.spv"), Shader::ShaderType::Fragment}});
        _renderer->SetShader("passthrough");
        _renderer->SetShader("red");
        CAST_DEBUG("Loaded shader");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        //_renderer->GetShader("passthrough")->use();
        static glm::vec3 verts[3]{glm::vec3(-1, -1, 1), glm::vec3(-1,1,1), glm::vec3(1,1,1)};
        static glm::vec3 cols[3]{glm::vec3(0, 1, 1), glm::vec3(1,1,0), glm::vec3(1,1,1)};
        _renderer->SubmitTriangle(-0.5, -0.5, 1);
        _renderer->Draw();
    }
    void DebugScene::unload(){}

}