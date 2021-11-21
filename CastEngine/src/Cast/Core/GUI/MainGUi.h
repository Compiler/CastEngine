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
                    static float f = 0.0f;
                    static int counter = 0;
                    ImGui::SetNextWindowPos(ImVec2(0, 0));
                    ImGui::Begin("LeftPanel");                          // Create a window called "Hello, world!" and append into it.

                    ImGui::Text("Cast Engine UI");               // Display some text (you can use a format strings too)
                    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state

                    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
                    ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

                    if (ImGui::Button("New Entity")){
                        counter++;
                    }      
                    if (ImGui::CollapsingHeader("Entity List")){
                        for(auto &&[entity, entityName]: sceneRegistry.view<NameComponent>().each()) {
                            currentEntity = entity;
                            ImGui::Text(entityName.name.c_str());
                        }             
                    }
                    ImGui::Text("counter = %d", counter);

                    ImGui::End();
                }

                {
                    ImGui::SetNextWindowPos(ImVec2(1080, 0));
                    ImGui::Begin("Entity Panel");                       
                    ImGui::Text("Entity Panel");        


                    ImGui::End();

                }



                ImGui::Render();
            }

    };
}