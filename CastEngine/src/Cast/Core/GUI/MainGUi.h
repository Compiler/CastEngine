#pragma once
#include <Cast/Vendor/ImGui/imgui.h>
#include <Cast/Vendor/entt/entity/registry.hpp>

#include <Cast/Core/ECS/Components/Components.h>
namespace Cast{

    class MainGUI{
        
        friend class EngineCore;
        
        public:
            ImVec4 clear_color = ImVec4(50.0f / 255.0f, 27.0f / 255.0f, 50.0f / 255.0f, 1.00f);
            bool show_demo_window = true;

            entt::entity currentEntity;

            void Render(entt::registry& sceneRegistry){
                ImGui::NewFrame();

                // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
                if(show_demo_window)
                ImGui::ShowDemoWindow(&show_demo_window);

                {
                    static int counter = 0;
                    ImGui::SetNextWindowPos(ImVec2(0, 0));
                    ImGui::Begin("LeftPanel");                          // Create a window called "Hello, world!" and append into it.

                    ImGui::Text("Cast Engine UI");               // Display some text (you can use a format strings too)
                    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state

                    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

                    if (ImGui::Button("New Entity")){

                    }      
                    static int count = 0;
                    bool selected = false;
                    if (ImGui::CollapsingHeader("Entity List")){
                        for(auto &&[entity, entityName]: sceneRegistry.view<NameComponent>().each()) {
                            
                            if(ImGui::Selectable(entityName.name.c_str(), selected)){
                                currentEntity = entity;
                                CAST_LOG("{} selected", entityName.name.c_str());
                            }
                        }             
                    }

                    ImGui::End();
                }

                {

                    int panel_width = 300;
                    ImGui::SetNextWindowSize(ImVec2(panel_width, Window::WINDOW_HEIGHT));
                    ImGui::SetNextWindowPos(ImVec2(Window::WINDOW_WIDTH - panel_width, 0));
                    ImGui::Begin("Entity Panel");           

                    if(sceneRegistry.any_of<NameComponent>(currentEntity)){
                        ImGui::Text("Entity: %s", sceneRegistry.get<NameComponent>(currentEntity).name.c_str());
                    } 

                    if(sceneRegistry.any_of<RenderableComponent>(currentEntity)){
                        auto& comp = sceneRegistry.get<RenderableComponent>(currentEntity);
                        ImGui::ColorEdit4("Sup", &comp.color.r);
                    }            


                    ImGui::End();

                }



                ImGui::Render();
            }

    };
}