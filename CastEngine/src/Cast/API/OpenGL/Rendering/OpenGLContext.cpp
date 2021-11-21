#include "OpenGLContext.h"

namespace Cast{

    OpenGLContext::OpenGLContext(){
        m_window = new OpenGLWindow(1920, 1080, "Cast Engine");
    }

    void OpenGLContext::Load(){
        RenderContext::Load();
        LoadImGUI();
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


    void OpenGLContext::LoadImGUI(){
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(m_window->getWindowHandle(), true);
        ImGui_ImplOpenGL3_Init("#version 460");



    }

    void OpenGLContext::BeginGUI(){
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
    }

    void OpenGLContext::EndGUI(){
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }




}