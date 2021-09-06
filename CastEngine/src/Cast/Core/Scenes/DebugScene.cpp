#include "DebugScene.h"

namespace Cast{

    void DebugScene::load(){
        //_shader.loadShader(CAST_INTERNAL_SHADER("passthrough.vert"), CAST_INTERNAL_SHADER("RayMarching_orig.glsl"));
        _shader.loadShader(CAST_INTERNAL_SHADER("passthrough.vert"), CAST_INTERNAL_SHADER("passthrough.frag"));
        CAST_DEBUG("Loaded shader");
        float ext = 0.95f;

        std::vector<float>&& vertices= { 
            -ext, -ext, 1, 1.0f,    1.0f, 0.0f, 1.0f, 1.0f,    
            -ext, ext, 1, 1.0f,     1.0f, 0.0f, 1.0f, 1.0f,
             ext, ext, 1, 1.0f,     1.0f, 0.0f, 1.0f, 1.0f,
            
            -ext, -ext, 1, 1.0f,    1.0f, 1.0f, 1.0f, 1.0f,    
             ext, -ext, 1,1.0f,     1.0f, 1.0f, 1.0f, 1.0f,
             ext, ext, 1, 1.0f,     1.0f, 1.0f, 1.0f, 1.0f};

        CAST_DEBUG("Finished loading debug scene");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        _shader.use();
        glm::vec3 verts[3]{glm::vec3(-1, -1, 1), glm::vec3(-1,1,1), glm::vec3(1,1,1)};
        glm::vec3 cols[3]{glm::vec3(0, 1, 1), glm::vec3(1,1,0), glm::vec3(1,1,1)};
        _renderer.SubmitTriangle(verts, cols);
        _renderer.Draw();
    }
    void DebugScene::unload(){}

}