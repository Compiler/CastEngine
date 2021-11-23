#pragma once
#include <Cast/Vendor/entt/entity/registry.hpp>
#include <Cast/Core/ECS/Components/Components.h>
#include <Cast/Core/Debug/Logger.h>
namespace Cast{

    class EntityFactory{
        
        public:
            EntityFactory() = delete;

            static entt::entity& GenerateDefaultEntity(entt::registry& registry, const char* name = "Entity");
    };
}