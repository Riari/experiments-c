#ifndef FLECS_BASIC_SYSTEM_H
#define FLECS_BASIC_SYSTEM_H

void ComponentASystem(ecs_iter_t *it) {
    ComponentA *c = ecs_term(it, ComponentA, 1);

    for (int i = 0; i < it->count; i ++) {
        // noop
    }
}

int ex_flecs_basic_system()
{
    ecs_world_t *world = ecs_init();

    ECS_COMPONENT_DEFINE(world, ComponentA);
    ecs_id_t componentA = ecs_id(ComponentA);

    ECS_SYSTEM(world, ComponentASystem, EcsOnUpdate, ComponentA);

    ecs_entity_t entityA = ecs_new_id(world);
    ComponentA *pComponentA = new ComponentA();
    ecs_set_id(world, entityA, componentA, sizeof(ComponentA), pComponentA);
    
    constexpr int maxTicks = 60;
    int ticks = 0;
    while(ecs_progress(world, 0) && ticks++ < maxTicks);

    return ecs_fini(world);
}

#endif // FLECS_BASIC_SYSTEM_H