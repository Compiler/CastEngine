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
        OpenGLVertexBuffer<float> buffer(std::move(vertices));
        buffer.init(GL_DYNAMIC_DRAW);

        Cast::VAOLayout layout{VAOElement{4}, VAOElement{4}};
        OpenGLVertexArray vao{std::move(layout)};


        CAST_DEBUG("Finished loading debug scene");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        _shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
    void DebugScene::unload(){}

}