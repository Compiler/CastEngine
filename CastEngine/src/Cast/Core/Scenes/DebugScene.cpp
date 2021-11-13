#include "DebugScene.h"
#include <glm/vec4.hpp>
namespace Cast{

    void DebugScene::load(){
        //_renderer->CreateShader("passthrough", {{CAST_INTERNAL_SHADER("passthrough.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        //_renderer->SetShader("passthrough");
        //_renderer->CreateShader("red", {{CAST_INTERNAL_SHADER("passthrough.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("red.frag"), Shader::ShaderType::Fragment}});
        //_renderer->SetShader("red");
        _renderer->CreateShader("passthrough_3d", {{CAST_INTERNAL_SHADER("passthrough_3d.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        _renderer->SetShader("passthrough_3d");
        CAST_DEBUG("Loaded shader");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        static float offset = 0;
        _renderer->clearColor(1.0, 0.3f, 0.6f, 1.0f);
        //offset += 0.0001;
        //_renderer->GetShader("passthrough")->use();
        static glm::vec3 verts[3]{glm::vec3(-1, -1, 1), glm::vec3(-1,1,1), glm::vec3(1,1,1)};
        static glm::vec3 cols[3]{glm::vec3(0, 1, 1), glm::vec3(1,1,0), glm::vec3(1,1,1)};
        _renderer->SetColor({0.12, 0.12, 0.9, 1});
        _renderer->SubmitTriangle(-0.5 + offset, -0.5, 0.25);
        _renderer->SetColor({0.9, 0.12, 0.12, 1});
        _renderer->SubmitTriangle(0.5 + -offset, -0.5, 0.25);
        _renderer->SetColor({0.12, 0.9, 0.12, 1});
        _renderer->SubmitCube({0.0f, 0.0f, 0.0f}, 0.25f);
        _renderer->Draw();
    }
    void DebugScene::unload(){}

}
