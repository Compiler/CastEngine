#include "OpenGLContext.h"

namespace Cast{

    OpenGLContext::OpenGLContext(){
        m_window = new OpenGLWindow(1920, 1080, "Cast Engine");
    }

    void OpenGLContext::Load(){
        RenderContext::Load();
    }
    void OpenGLContext::Update(){
        RenderContext::Update();
        this->m_window->update();
    }
    void OpenGLContext::Render(){
        RenderContext::Render();
        this->m_window->render();
    }
    void OpenGLContext::Unload(){
        RenderContext::Unload();
        this->m_window->destroy();
    }

    void OpenGLContext::clearColor(float r, float g, float b, float a){
        glClearColor(r,g,b,a);
    }
    void OpenGLContext::clearColorBit(){
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void OpenGLContext::clearDepthBit(){
        glClear(GL_DEPTH_BUFFER_BIT);
    }




}