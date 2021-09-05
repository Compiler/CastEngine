#include "DebugScene.h"

namespace Cast{

    void DebugScene::load(){
        //_shader.loadShader(CAST_INTERNAL_SHADER("passthrough.vert"), CAST_INTERNAL_SHADER("RayMarching_orig.glsl"));
        _shader.loadShader(CAST_INTERNAL_SHADER("passthrough.vert"), CAST_INTERNAL_SHADER("RayMarching_incl.glsl"));
        CAST_DEBUG("Loaded shader");
        float ext = 0.95f;
        
        std::vector<float>&& vertices= { -ext, -ext, 1, 1.0f,    1.0f, 0.0f, 1.0f, 1.0f,    
            -ext, ext, 1,1.0f,     1.0f, 0.0f, 1.0f, 1.0f,
            ext, ext, 1, 1.0f,     1.0f, 0.0f, 1.0f, 1.0f,
            
            -ext, -ext, 1, 1.0f,    1.0f, 0.0f, 1.0f, 1.0f,    
            ext, -ext, 1,1.0f,     1.0f, 0.0f, 1.0f, 1.0f,
            ext, ext, 1, 1.0f,     1.0f, 0.0f, 1.0f, 1.0f};
        OpenGLVertexBuffer<float> buffer(std::move(vertices));
        buffer.init(GL_DYNAMIC_DRAW);
        Cast::VAOLayout layout;
        layout.strideCount.push_back(std::pair<int, int>(0, 4));
        layout.strideCount.push_back(std::pair<int, int>(4, 4));
        OpenGLVertexArray vao{layout};
        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(4 * sizeof(float)));
        glEnableVertexAttribArray(0);  
        glEnableVertexAttribArray(1);  


        CAST_DEBUG("Finished loading debug scene");
    }
    void DebugScene::update(){}
    void DebugScene::render(){
        _shader.use();
        _shader.uniform_set1Float("u_time", glfwGetTime());
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
    void DebugScene::unload(){}

}