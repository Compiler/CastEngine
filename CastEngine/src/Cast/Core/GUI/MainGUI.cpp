#include "MainGUI.h"



namespace Cast{


    void MainGUI::Render(entt::registry& sceneRegistry, PerspectiveCamera& camera){
        //static bool setStyle = false;
        //if(!setStyle){_SetStyle(); setStyle = true;}
        ImGui::NewFrame();

        if(show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        static int panel_width = Window::WINDOW_WIDTH * 0.2;
        bool OpenGL = RenderContext::GetAPI() == RenderContext::API::OpenGL;
        bool Vulkan = RenderContext::GetAPI() == RenderContext::API::Vulkan;
        {
            static int counter = 0;
            ImGui::SetNextWindowPos(ImVec2(0, 0));
            ImGui::SetNextWindowSize(ImVec2(panel_width, Window::WINDOW_HEIGHT));
            ImGui::Begin("LeftPanel");                          // Create a window called "Hello, world!" and append into it.


            ImGui::Text("Cast Engine UI");               // Display some text (you can use a format strings too)
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::SameLine();
            if(ImGui::Checkbox("OpenGL", &OpenGL)){
                Vulkan = false;
                RenderContext::setAPI(RenderContext::API::OpenGL);
            }
            ImGui::SameLine();
            if(ImGui::Checkbox("Vulkan", &Vulkan)){
                OpenGL = false;
                RenderContext::setAPI(RenderContext::API::Vulkan);
            }

            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("New Entity")){

            }      
            if(InputManager::isMouseReleased(MouseCodes::MOUSE_BUTTON_MIDDLE)){
                auto e = EntityFactory::GenerateDefaultEntity(sceneRegistry, "Generated");
                auto& trans = sceneRegistry.get<TransformComponent>(e);
                auto newPos = _GetRayClick(camera);
                trans.position.x = newPos.x;
                trans.position.y = newPos.y;
                trans.position.z = newPos.z;

            }
            static int count = 0;
            static entt::entity deleteEntity;
            bool selected = false;
            static bool openEntityRightClickMenu = false;
            static glm::vec2 mousePosRightClickEntity;
            if (ImGui::CollapsingHeader("Entity List")){
                for(auto &&[entity, entityName]: sceneRegistry.view<NameComponent>().each()) {
                    
                    if(ImGui::Selectable(entityName.name.c_str(), selected)){
                        currentEntity = entity;
                        CAST_LOG("{} selected", entityName.name.c_str());
                    }
                    if(InputManager::isMousePressed(MouseCodes::MOUSE_BUTTON_RIGHT) && ImGui::IsItemHovered()){
                        openEntityRightClickMenu = true;
                        mousePosRightClickEntity = InputManager::getMouseMovedPosition();
                        deleteEntity = entity;
                        CAST_LOG("Deciding on entity: {}", entityName.name.c_str());
                    }
                    
                }             
            }

            if(openEntityRightClickMenu){
                ImGui::SetNextWindowPos(ImVec2(mousePosRightClickEntity.x, mousePosRightClickEntity.y-25));
                ImGui::Begin("Entity Options Menu", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |ImGuiWindowFlags_AlwaysAutoResize);
                if(ImGui::Selectable("Delete Entity")){
                    sceneRegistry.destroy(deleteEntity);
                    openEntityRightClickMenu = false;
                }
                ImGui::End();
            }

            ImGui::End();
        }

        {

            ImGui::SetNextWindowSize(ImVec2(panel_width, Window::WINDOW_HEIGHT));
            ImGui::SetNextWindowPos(ImVec2(Window::WINDOW_WIDTH - panel_width, 0));
            ImGui::Begin("Entity Panel");           

            if(sceneRegistry.valid(currentEntity)){
                if(sceneRegistry.any_of<NameComponent>(currentEntity)){
                    sceneRegistry.get<NameComponent>(currentEntity).RenderComponentView();
                } 

                if(sceneRegistry.any_of<TransformComponent>(currentEntity)){
                    sceneRegistry.get<TransformComponent>(currentEntity).RenderComponentView();
                }    
                if(sceneRegistry.any_of<CubeComponent>(currentEntity)){
                    sceneRegistry.get<CubeComponent>(currentEntity).RenderComponentView();
                }    
                
                if(sceneRegistry.any_of<RenderableComponent>(currentEntity)){
                    sceneRegistry.get<RenderableComponent>(currentEntity).RenderComponentView();
                }    
            }




            ImGui::End();

        }

        static bool openRightClickMenu = false;
        static glm::vec2 mousePositionOnCreation{};
        if(InputManager::isMousePressed(MouseCodes::MOUSE_BUTTON_RIGHT) && !ImGui::IsWindowHovered() && !ImGui::IsAnyItemHovered()){
            openRightClickMenu = true;
            mousePositionOnCreation = InputManager::getMouseMovedPosition();
        }
        
        if(openRightClickMenu){
            ImGui::SetNextWindowPos(ImVec2(mousePositionOnCreation.x, mousePositionOnCreation.y));
            ImGui::Begin("Creation Menu", nullptr, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |ImGuiWindowFlags_AlwaysAutoResize);
            if(InputManager::isMousePressed(MouseCodes::MOUSE_BUTTON_LEFT) && !ImGui::IsWindowHovered()){
                openRightClickMenu = false;
            }
            
            if(ImGui::Selectable("Create new entity?")){
                char buf[64] = "Sup\0";
                ImGui::InputText("Name: ", buf, IM_ARRAYSIZE(buf));
                currentEntity = EntityFactory::GenerateDefaultEntity(sceneRegistry, buf);
                openRightClickMenu = false;
            }
            //end
            ImGui::End();

        }


        ImGui::Render();
    }

}