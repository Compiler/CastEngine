#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/ECS/Components/Components.h>
#include <Cast/Core/Utils/MathUtils.h>
#include <Cast/Core/Rendering/Shapes/Cube.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Scenes/Scene.h>
#include <Cast/Core/Input/InputManager.h>
namespace Cast{

    class StressTestScene : public Scene{
        private:
            std::vector<Cube> _cubes;
        public:
            glm::vec4 clearColor = {0.1, 0.1, 0.1, 1};
            void Initialize();
            void Load();
            void Update();
            void Render();
            void UnLoad();
            ~StressTestScene(){CAST_WARN("StresTestScene Unloaded");}
    };

}