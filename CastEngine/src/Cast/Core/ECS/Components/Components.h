#pragma once
#include <glm/vec4.hpp>
#include <string>
#include <Cast/Vendor/ImGui/imgui.h>

#define CAST_COMPONENT(x) \
struct x : public Component


namespace Cast{




    struct Component{

        virtual void RenderComponentView() = 0;
    };


    CAST_COMPONENT(NameComponent){
        inline static int count = 0;
        std::string name = "Entity" + count;
        NameComponent(){count++;}
        NameComponent(const char* name){this->name = name;count++;}
        NameComponent(std::string name){this->name = name;count++;}
        void RenderComponentView(){
			char buf[64] = "";
			bool first = true;
			if(first){
				strcpy(buf, this->name.c_str());
				first = false;
			}
			if(ImGui::InputText("Name: ", buf, IM_ARRAYSIZE(buf)))
				this->name = buf;
        }
    };
    CAST_COMPONENT(TransformComponent){
        
        glm::vec4 position{0};
        glm::vec4 rotation{0};
        glm::vec4 scale{0};

        // void RenderComponentView(){
        //     if(ImGui::CollapsingHeader("Transform Component", true)){
        //         ImGui::InputFloat4("Position", &this->position[0]);
        //         ImGui::InputFloat4("Rotation", &this->rotation[0]);
        //         ImGui::InputFloat4("Scale", &this->scale[0]);
        //     }
        // }


        void RenderComponentView(){
            if(ImGui::CollapsingHeader("Transform Component", ImGuiTreeNodeFlags_DefaultOpen)){
					ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_FrameBorderSize, 1);
					static float currentWidth = ImGui::GetContentRegionAvailWidth();
					static float currentHeight = ImGui::GetContentRegionAvail().y;
					ImGui::PushStyleVar(ImGuiStyleVar_::ImGuiStyleVar_FramePadding, ImVec2(currentWidth * 0.025, currentHeight * 0.0025));
					static ImVec2 spacing(0, 10);
					static ImVec4 redCol(1, 0, 0, 1);
					static ImVec4 greCol(0, 1, 0, 1);
					static ImVec4 bluCol(0.5, 0.5, 1, 1);
					float mag = 6.25f;
					ImGui::Dummy(spacing);
					ImGui::AlignTextToFramePadding();
					ImGui::Text("Position");
					float progression = currentWidth / 5.0f;
					float subCompCount = 1.0f;
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.3,0.1,0.1,1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(redCol, "X"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::AlignTextToFramePadding(); ImGui::InputScalar("##XPositionTransform", ImGuiDataType_::ImGuiDataType_Float, &position.x, 0, 0, "%.2f");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.1, 0.3, 0.1, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(greCol, "Y"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::AlignTextToFramePadding(); ImGui::InputScalar("##YPositionTransform", ImGuiDataType_::ImGuiDataType_Float, &position.y, 0, 0, "%.2f");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.1, 0.1, 0.3, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(bluCol, "Z"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::AlignTextToFramePadding(); ImGui::InputScalar("##ZPositionTransform", ImGuiDataType_::ImGuiDataType_Float, &position.z, 0, 0, "%.2f");
					/*ImGui::InputFloat("Y", &position.y);
					ImGui::InputFloat("Z", &position.z);*/
					ImGui::Dummy(spacing);
					subCompCount = 1.0f;
					ImGui::AlignTextToFramePadding();
					ImGui::Text("Scale");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.3, 0.1, 0.1, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(redCol, "W"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::InputScalar("##XScaleTransform", ImGuiDataType_::ImGuiDataType_Float, &scale.x, 0, 0, "%.2f");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.1, 0.3, 0.1, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(greCol, "H"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::InputScalar("##YScaleTransform", ImGuiDataType_::ImGuiDataType_Float, &scale.y, 0, 0, "%.2f");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.1, 0.1, 0.3, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(bluCol, "D"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::InputScalar("##ZScaleTransform", ImGuiDataType_::ImGuiDataType_Float, &scale.z, 0, 0, "%.2f");
					ImGui::Dummy(spacing);
					subCompCount = 1.0f;
					ImGui::AlignTextToFramePadding();
					ImGui::Text("Rotation");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.3, 0.1, 0.1, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(redCol, "X"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::InputScalar("##XRotationTransform", ImGuiDataType_::ImGuiDataType_Float, &rotation.x, 0, 0, "%.2f");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.1, 0.3, 0.1, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(greCol, "Y"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::InputScalar("##YRotationTransform", ImGuiDataType_::ImGuiDataType_Float, &rotation.y, 0, 0, "%.2f");
					ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_FrameBg, ImVec4(0.1, 0.1, 0.3, 1));
					ImGui::SameLine(progression * subCompCount++); ImGui::TextColored(bluCol, "Z"); ImGui::SameLine(0, 5); ImGui::SetNextItemWidth(currentWidth / mag);
					ImGui::InputScalar("##ZRotationTransform", ImGuiDataType_::ImGuiDataType_Float, &rotation.z, 0, 0, "%.2f");
					ImGui::Dummy(spacing);
					ImGui::PopStyleVar();
					ImGui::PopStyleVar();

					ImGui::PopStyleColor(); ImGui::PopStyleColor(); ImGui::PopStyleColor();
					ImGui::PopStyleColor(); ImGui::PopStyleColor(); ImGui::PopStyleColor();
					ImGui::PopStyleColor(); ImGui::PopStyleColor(); ImGui::PopStyleColor();
				}
        }

    };

    CAST_COMPONENT(RenderableComponent){
        enum Shape{Triangle, Cube, Rectangle} renderShape = Shape::Cube;
        glm::vec4 color;

        void RenderComponentView(){
            if(ImGui::CollapsingHeader("Renderable Component", ImGuiTreeNodeFlags_DefaultOpen)){
                ImGui::ColorPicker4("Color", &this->color[0], ImGuiColorEditFlags_PickerHueWheel);
                static const char* list[] = {"Triangle", "Cube", "Rectangle"};
                static int curItem = renderShape == Triangle ? 0 : renderShape == Cube ? 1 : 2;
                ImGui::ListBox("Shape Selection (Unsupported)", &curItem, list, 3);
                renderShape = Shape(curItem);
            }
        }
    };

    CAST_COMPONENT(CubeComponent){
        float sideLength = 1.0f;

        void RenderComponentView(){
            if(ImGui::CollapsingHeader("Cube Component", ImGuiTreeNodeFlags_DefaultOpen)){
                ImGui::SliderFloat("Side Length", &this->sideLength, 0, 3);
            }
        }
    };
}