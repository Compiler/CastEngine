#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/ECS/Components/Components.h>
#include <Cast/Core/Utils/MathUtils.h>
#include <Cast/Core/Rendering/Shapes/Cube.h>
#include <Cast/Core/Debug/Logger.h>
#include <Cast/Core/Input/InputManager.h>
namespace Cast{

    class StressTestScene{
        private:
            entt::registry _registry{};
            std::vector<Cube> _cubes;
            Renderer* _renderer;
        public:
            glm::vec4 clearColor = {0.1, 0.1, 0.1, 1};
            void init();
            void load();
            void update();
            void render();
            void unload();
            void setRenderer(Renderer* renderer){this->_renderer = renderer;}
            inline entt::registry& getRegistry(){return this->_registry;}
            ~StressTestScene(){CAST_WARN("StresTestScene Unloaded");}
    };

}