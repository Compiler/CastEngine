#pragma once
#include <unordered_map>
#include <Cast/Core/Scenes/Scene.h>
namespace Cast{
    class Scene;
    class SceneManager{
        private:
            std::unordered_map<int, Scene*> _scenes;
            Scene* _currentScene;

        public:
            void addScene(Scene* newScene);
            void setScene(Scene* newScene);

            void Load();
            void Update();
            void Render();
            void UnLoad();

            inline Scene* getCurrentScene()const{CAST_ASSERT(_currentScene);return this->_currentScene;}

    };

}