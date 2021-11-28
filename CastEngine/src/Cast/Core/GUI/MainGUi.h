#pragma once
#include <Cast/Vendor/ImGui/imgui.h>
#include <Cast/Vendor/entt/entity/registry.hpp>
#include <glm/vec3.hpp>
#include <Cast/Core/ECS/Components/Components.h>
#include <Cast/Core/Utils/Files/FileLoaderFactory.h>
#include <Cast/Core/ECS/EntityFactory.h>
#include <Cast/Core/Rendering/Window.h>
#include <Cast/Core/Input/InputManager.h>
#include <Cast/Core/Rendering/PerspectiveCamera.h>
namespace Cast{

    class MainGUI{
        
        friend class EngineCore;
        private:
            void _RenderPostProcessing(){

            }        
        public:
            static inline void _SetStyle(){
                constexpr auto ColorFromBytes = [](uint8_t r, uint8_t g, uint8_t b)
                {
                    return ImVec4((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 1.0f);
                };

                auto& style = ImGui::GetStyle();
                ImVec4* colors = style.Colors;

                const ImVec4 bgColor           = ColorFromBytes(10, 10, 10);
                const ImVec4 lightBgColor      = ColorFromBytes(82, 82, 85);
                const ImVec4 veryLightBgColor  = ColorFromBytes(90, 90, 95);

                const ImVec4 panelColor        = ColorFromBytes(51, 51, 55);
                const ImVec4 panelHoverColor   = ColorFromBytes(29, 151, 236);
                const ImVec4 panelActiveColor  = ColorFromBytes(0, 119, 200);

                const ImVec4 textColor         = ColorFromBytes(255, 255, 255);
                const ImVec4 textDisabledColor = ColorFromBytes(151, 151, 151);
                const ImVec4 borderColor       = ColorFromBytes(78, 78, 78);

                colors[ImGuiCol_Text]                 = textColor;
                colors[ImGuiCol_TextDisabled]         = textDisabledColor;
                colors[ImGuiCol_TextSelectedBg]       = panelActiveColor;
                colors[ImGuiCol_WindowBg]             = bgColor;
                colors[ImGuiCol_ChildBg]              = bgColor;
                colors[ImGuiCol_PopupBg]              = bgColor;
                colors[ImGuiCol_Border]               = borderColor;
                colors[ImGuiCol_BorderShadow]         = borderColor;
                colors[ImGuiCol_FrameBg]              = panelColor;
                colors[ImGuiCol_FrameBgHovered]       = panelHoverColor;
                colors[ImGuiCol_FrameBgActive]        = panelActiveColor;
                colors[ImGuiCol_TitleBg]              = bgColor;
                colors[ImGuiCol_TitleBgActive]        = bgColor;
                colors[ImGuiCol_TitleBgCollapsed]     = bgColor;
                colors[ImGuiCol_MenuBarBg]            = panelColor;
                colors[ImGuiCol_ScrollbarBg]          = panelColor;
                colors[ImGuiCol_ScrollbarGrab]        = lightBgColor;
                colors[ImGuiCol_ScrollbarGrabHovered] = veryLightBgColor;
                colors[ImGuiCol_ScrollbarGrabActive]  = veryLightBgColor;
                colors[ImGuiCol_CheckMark]            = panelActiveColor;
                colors[ImGuiCol_SliderGrab]           = panelHoverColor;
                colors[ImGuiCol_SliderGrabActive]     = panelActiveColor;
                colors[ImGuiCol_Button]               = panelColor;
                colors[ImGuiCol_ButtonHovered]        = panelHoverColor;
                colors[ImGuiCol_ButtonActive]         = panelHoverColor;
                colors[ImGuiCol_Header]               = panelColor;
                colors[ImGuiCol_HeaderHovered]        = panelHoverColor;
                colors[ImGuiCol_HeaderActive]         = panelActiveColor;
                colors[ImGuiCol_Separator]            = borderColor;
                colors[ImGuiCol_SeparatorHovered]     = borderColor;
                colors[ImGuiCol_SeparatorActive]      = borderColor;
                colors[ImGuiCol_ResizeGrip]           = bgColor;
                colors[ImGuiCol_ResizeGripHovered]    = panelColor;
                colors[ImGuiCol_ResizeGripActive]     = lightBgColor;
                colors[ImGuiCol_PlotLines]            = panelActiveColor;
                colors[ImGuiCol_PlotLinesHovered]     = panelHoverColor;
                colors[ImGuiCol_PlotHistogram]        = panelActiveColor;
                colors[ImGuiCol_PlotHistogramHovered] = panelHoverColor;
                colors[ImGuiCol_ModalWindowDimBg]       = bgColor;
                colors[ImGuiCol_DragDropTarget]       = bgColor;
                colors[ImGuiCol_NavHighlight]         = bgColor;
                colors[ImGuiCol_DockingPreview]       = panelActiveColor;
                colors[ImGuiCol_Tab]                  = bgColor;
                colors[ImGuiCol_TabActive]            = panelActiveColor;
                colors[ImGuiCol_TabUnfocused]         = bgColor;
                colors[ImGuiCol_TabUnfocusedActive]   = panelActiveColor;
                colors[ImGuiCol_TabHovered]           = panelHoverColor;

                style.WindowRounding    = 0.0f;
                style.ChildRounding     = 0.0f;
                style.FrameRounding     = 0.0f;
                style.GrabRounding      = 0.0f;
                style.PopupRounding     = 0.0f;
                style.ScrollbarRounding = 0.0f;
                style.TabRounding       = 0.0f;

                //ImGui::GetIO().Fonts->AddFontFromFileTTF(CAST_INTERNAL_FONTS("Ruda/Ruda-Bold.ttf"), 12);
                //ImGui::GetIO().Fonts->AddFontFromFileTTF(CAST_INTERNAL_FONTS("Ruda/Ruda-Bold.ttf"), 10);
                //ImGui::GetIO().Fonts->AddFontFromFileTTF(CAST_INTERNAL_FONTS("Ruda/Ruda-Bold.ttf"), 14);
                //ImGui::GetIO().Fonts->AddFontFromFileTTF(CAST_INTERNAL_FONTS("Ruda/Ruda-Bold.ttf"), 18);

            }


            glm::vec3 _GetRayClick(PerspectiveCamera& camera){
                glm::vec2 mousePos2D = InputManager::getMouseMovedPosition();
                float x = (2.0f * mousePos2D.x) / Window::WINDOW_WIDTH - 1.0f;
                float y = 1.0f - (2.0f * mousePos2D.y) / Window::WINDOW_HEIGHT;
                float z = 1.0f;
                glm::vec3 ray_nds = glm::vec3(x, y, z);
                glm::vec4 ray_clip = glm::vec4(ray_nds.x, ray_nds.y, -1.0, 1.0);
                glm::vec4 ray_eye = glm::inverse(camera.getProjection()) * ray_clip;
                ray_eye = glm::vec4(ray_eye.x, ray_eye.y, -1.0, 0.0);
                glm::vec4 prod = glm::inverse(camera.getView()) * ray_eye;
                glm::vec3 ray_wor = {prod.x, prod.y, prod.z};
                return ray_wor;
            }


        public:
            ImVec4 clear_color = ImVec4(255.0f / 255.0f, 151.0f / 255.0f, 255.0f / 255.0f, 1.00f);
            bool show_demo_window = true;

            entt::entity currentEntity;

            void Render(entt::registry& sceneRegistry, PerspectiveCamera& camera){
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
                    ImGui::End();
                }


                ImGui::Render();
            }

    };
}