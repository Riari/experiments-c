#ifndef FLECS_ARCHETYPE_ACCESS_H
#define FLECS_ARCHETYPE_ACCESS_H

void print_archetype(ecs_world_t *world, ecs_entity_t entity)
{
    ecs_type_t type = ecs_get_type(world, entity);
    ecs_id_t *ids = ecs_vector_first(type, ecs_entity_t);
    for (int i = 0; i < ecs_vector_count(type); i++) {
        printf("Archetype %s has component ID %llu\n", ecs_type_str(world, type), ids[i]);
    }
}

int ex_flecs_archetype_access()
{
    ecs_world_t *world = ecs_init();

    ecs_id_t componentA = register_component(world, "ComponentA", sizeof(ComponentA), sizeof(ComponentA));
    ecs_id_t componentB = register_component(world, "ComponentB", sizeof(ComponentB), sizeof(ComponentB));

    ecs_id_t tagA = ecs_new_id(world);
    ecs_id_t tagB = ecs_new_id(world);

    ecs_entity_t entityA = ecs_new_id(world);
    ecs_add_id(world, entityA, componentA);
    ecs_add_id(world, entityA, componentB);
    ecs_add_id(world, entityA, tagA);

    ecs_entity_t entityB = ecs_new_id(world);
    ecs_add_id(world, entityB, componentB);
    ecs_add_id(world, entityB, tagB);
    
    print_archetype(world, entityA);
    printf("\n");
    print_archetype(world, entityB);

    return ecs_fini(world);
}

#endif // FLECS_ARCHETYPE_ACCESS_H