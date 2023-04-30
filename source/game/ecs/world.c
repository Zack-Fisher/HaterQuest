#include "world.h"

#include "../ui.h"
#include "../mover.h"

void init_world(World *world) {
    void registry(World* world) 
    {
        //WORLD
        REGISTER_COMPONENT(&world, Position);
        REGISTER_COMPONENT(&world, Controller);
        REGISTER_COMPONENT(&world, Velocity);
        REGISTER_COMPONENT(&world, Mover);

        //UI
        REGISTER_COMPONENT(&world, Button);
        REGISTER_COMPONENT(&world, Label);
        REGISTER_COMPONENT(&world, ProgressBar);
    }

    world->component_arrays = NULL;
    world->entity_count = 0;

    registry(world);
}

Entity create_entity(World *world) {
    Entity entity_id = world->entity_count++;
    return entity_id;
}

void add_component(World *world, Entity entity_id, const char *component_type, void *component_data) {
    ComponentArray *array;
    HASH_FIND_STR(world->component_arrays, component_type, array);
    if (array) {
        memcpy((char *)array->array + array->element_size * entity_id, component_data, array->element_size);
        array->enabled[entity_id] = true;
    }
}

