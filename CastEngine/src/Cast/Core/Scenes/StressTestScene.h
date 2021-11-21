#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/ECS/Components/TransformComponent.h>
#include <Cast/Core/Rendering/Shapes/Cube.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Input/InputManager.h>
namespace Cast{

    class StressTestScene{
        private:
            std::vector<Cube> _cubes;
            Renderer* _renderer;
        public:
            void load();
            void update();
            void render();
            void unload();
            void setRenderer(Renderer* renderer){this->_renderer = renderer;}
            ~StressTestScene(){CAST_WARN("StresTestScene Unloaded");}
    };

}