#include "DebugScene.h"
#include <glm/vec4.hpp>
namespace Cast{

    void DebugScene::load(){
        //_renderer->CreateShader("passthrough", {{CAST_INTERNAL_SHADER("passthrough.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        //_renderer->SetShader("passthrough");
        //_renderer->CreateShader("red", {{CAST_INTERNAL_SHADER("passthrough.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("red.frag"), Shader::ShaderType::Fragment}});
        //_renderer->SetShader("red");
        _renderer->CreateShader("passthrough_3d", {{CAST_INTERNAL_SHADER("passthrough_3d.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("passthrough.frag"), Shader::ShaderType::Fragment}});
        _renderer->CreateShader("blinn_phong", {{CAST_INTERNAL_SHADER("blinn_phong.vert"), Shader::ShaderType::Vertex}, {CAST_INTERNAL_SHADER("blinn_phong.frag"), Shader::ShaderType::Fragment}});
        _renderer->SetShader("passthrough_3d");
        _renderer->SetShader("blinn_phong");
        CAST_DEBUG("Loaded shaders");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        static float offset = 0;
        static Cube cube{{0, 0, 0}, 0.5};
        static Cube cube2{{-1, 0, 1}, 0.5, 45.0f, {1.0, 0, 1.0}, {0, 0, 1, 1}};
        _renderer->SubmitTriangle(0.375, 0.5, 0.125);
        _renderer->SubmitTriangle(0.5, 0.5, 0.125);
        _renderer->SetColor({0.12, 0.12, 0.9, 1});
        _renderer->SubmitTriangle(-0.5 + offset, -0.5, 0.25);
        _renderer->SetColor({0.9, 0.12, 0.12, 1});
        _renderer->SubmitTriangle(0.5 + -offset, -0.5, 0.25);
        _renderer->SetColor({0.12, 0.9, 0.12, 1});

        if(InputManager::isKeyPressed(KeyCodes::KEY_LEFT)){
            cube.Rotate(-1, glm::vec3(0,1,0));
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_RIGHT)){
            cube.Rotate(1, glm::vec3(0,1,0));
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_UP)){
            cube.Rotate(1, glm::vec3(1, 0, 0));
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_DOWN)){
            cube.Rotate(-1, glm::vec3(1, 0, 0));
        }
        if(InputManager::isKeyReleased(KeyCodes::KEY_1)){
            _renderer->SetShader("blinn_phong");
        }
        if(InputManager::isKeyReleased(KeyCodes::KEY_2)){
            _renderer->SetShader("passthrough_3d");
        }
        float speed = 0.01f;
        if(InputManager::isKeyPressed(KeyCodes::KEY_A)){
            cube.Translate({speed, 0, 0});
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_D)){
            cube.Translate({-speed, 0, 0});
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_W)){
            cube.Translate({0, speed, 0});
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_S)){
            cube.Translate({0, -speed, 0});
        }

        if(InputManager::isKeyPressed(KeyCodes::KEY_ENTER)){
            cube.SetRotation(0, {1,1,1});
        }

        if(InputManager::isKeyPressed(KeyCodes::KEY_O)){
            cube.Scale({1.015, 1.015, 1.015});
        }
        if(InputManager::isKeyPressed(KeyCodes::KEY_P)){
            cube.Scale({0.95, 0.95, 0.95});
        }

        _renderer->SubmitVertexBuffer(cube.getRendererVertices());

        cube.Load();
        //_renderer->SubmitVertexBuffer(cube2.getRendererVertices());
        _renderer->SubmitCube({0.0f, 0.0f, 0.0f}, 0.25f);
        _renderer->clearColor(0.1f, 0.1f, 0.15f, 1.0f);
        
        _renderer->Draw();
    }
    void DebugScene::unload(){}

}
