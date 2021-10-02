#include "DebugScene.h"
#include <glm/vec4.hpp>
namespace Cast{

    void DebugScene::load(){
        _renderer->SetShader("passthrough", {{CAST_INTERNAL_SHADER("passthrough.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        CAST_DEBUG("Loaded shader");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        _renderer->GetShader("passthrough")->use();
        static glm::vec3 verts[3]{glm::vec3(-1, -1, 1), glm::vec3(-1,1,1), glm::vec3(1,1,1)};
        static glm::vec3 cols[3]{glm::vec3(0, 1, 1), glm::vec3(1,1,0), glm::vec3(1,1,1)};
        _renderer->SubmitTriangle(-0.5, -0.5, 1);
        _renderer->Draw();
    }
    void DebugScene::unload(){}

}