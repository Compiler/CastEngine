#pragma once
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/Rendering/Shapes/Cube.h>
#include <Cast/Core/Debug/Logger.h>
namespace Cast{

    class DebugScene{
        private:
            Renderer* _renderer;
        public:
            void load();
            void update();
            void render();
            void unload();
            void setRenderer(Renderer* renderer){this->_renderer = renderer;}
    };

}