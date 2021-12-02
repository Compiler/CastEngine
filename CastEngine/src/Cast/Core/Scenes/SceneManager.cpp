#include "SceneManager.h"

namespace Cast{

    void SceneManager::addScene(Scene* newScene){
        if(!_currentScene) _currentScene = newScene;
        newScene->_sceneID = Scene::_scene_count;
        _scenes.insert({Scene::_scene_count++, newScene});
    }
    
    void SceneManager::setScene(Scene* newScene){
        CAST_ASSERT(newScene);
        CAST_ASSERT(_scenes.find(newScene->_sceneID) != _scenes.end());
        _currentScene = _scenes[newScene->_sceneID];
    }


    void SceneManager::Load(){
        CAST_ASSERT(_currentScene);
        _currentScene->Load();
    }

    void SceneManager::Update(){
        CAST_ASSERT(_currentScene);
        _currentScene->Update();
    }

    void SceneManager::Render(){
        CAST_ASSERT(_currentScene);
        _currentScene->Render();
    }

    void SceneManager::UnLoad(){
        CAST_ASSERT(_currentScene);
        _currentScene->UnLoad();
    }


}