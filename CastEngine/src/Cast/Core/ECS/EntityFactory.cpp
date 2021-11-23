#include "EntityFactory.h"

namespace Cast{

    entt::entity& EntityFactory::GenerateDefaultEntity(entt::registry& registry, const char* name){
        CAST_DEBUG("Generating new entity");
        static entt::entity generatedEntity;
        generatedEntity = registry.create();
        TransformComponent& tComp = registry.emplace<TransformComponent>(generatedEntity);
        RenderableComponent& rComp = registry.emplace<RenderableComponent>(generatedEntity);
        CubeComponent& cComp = registry.emplace<CubeComponent>(generatedEntity);
        registry.emplace<NameComponent>(generatedEntity, name);
        
        tComp.position = {0, 0, 0, 1};
        tComp.rotation = {0, 0, 0, 1};
        tComp.scale = {1, 1, 1, 1};
        rComp.color = {1, 1, 1, 1};
        cComp.sideLength = 0.5;

        CAST_DEBUG("Returning entity");
        return generatedEntity;

    }

}