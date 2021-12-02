#pragma once
#include <Cast/Vendor/entt/entity/registry.hpp>
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/Rendering/Renderer.h>
#include <Cast/Core/Scenes/SceneManager.h>
namespace Cast{
    using SceneID = uint32_t;
    class Scene{
        friend class SceneManager;
        private:
            static inline SceneID _scene_count = 0;
            SceneID _sceneID;
        protected:
            entt::registry m_registry{};
            Renderer* m_renderer;
        public:
            virtual void Load() = 0;
            virtual void Update() = 0;
            virtual void Render() = 0;
            virtual void UnLoad() = 0;


            void setRenderer(Renderer* renderer);
            inline entt::registry& getRegistry(){return this->m_registry;}

    };

}