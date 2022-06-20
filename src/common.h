#ifndef COMMON_H
#define COMMON_H

typedef struct ComponentA
{
    int value;
} ComponentA;

typedef struct ComponentB
{
    int value;
} ComponentB;

ECS_COMPONENT_DECLARE(ComponentA);
ECS_COMPONENT_DECLARE(ComponentB);

ecs_entity_t register_component(ecs_world_t *world, const char *name, uint32_t size, uint32_t alignment)
{
    ecs_component_desc_t desc = {0};
    desc.entity.name = name;
    desc.type.size = size;
    desc.type.alignment = alignment;
    return ecs_component_init(world, &desc);
}

#endif