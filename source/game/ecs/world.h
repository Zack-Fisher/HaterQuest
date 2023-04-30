#pragma once

#include "uthash.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t Entity;

#define MAX_ENTITIES 1024

typedef struct {
    void *array;
    size_t element_size;
    bool enabled[MAX_ENTITIES];
    UT_hash_handle hh;
} ComponentArray;

typedef struct {
    ComponentArray *component_arrays;
    uint32_t entity_count;
} World;

#define REGISTER_COMPONENT(world, component_type) do { \
    ComponentArray *new_array = malloc(sizeof(ComponentArray)); \
    new_array->array = calloc(MAX_ENTITIES, sizeof(component_type)); \
    new_array->element_size = sizeof(component_type); \
    for (int i = 0; i < MAX_ENTITIES; ++i) { \
        new_array->enabled[i] = false; \
    } \
    HASH_ADD_KEYPTR(hh, *world->component_arrays, #component_type, strlen(#component_type), new_array); \
} while (0)

#define SYSTEM_H(system_name) \
    void system_name(World *world, float delta_time);

// call a system ergonomically
#define CALL(func) func(&world, deltaTime)

// pass in two code blocks, loop code then precode
// just pass in nothing if there's no precode.
// IMPORTANT NOTE: DON'T PASS IN BLOCKS FOR THE COMPONENT OR PRELOOP CODE.
// YOU NEED TO PASS AROUND VARIABLES, AND THEY'LL GO OUT OF SCOPE.
#define SYSTEM(system_name, component_names, code, pre_loop_code) \
    void system_name(World *world, float delta_time) { \
        pre_loop_code \
        for (Entity entity_id = 0; entity_id < world->entity_count; ++entity_id) { \
            bool execute_code = true; \
            component_names \
            if (execute_code) { \
                code \
            } else {printf("%d not found\n", entity_id);}\
        } \
    }

#define GET_COMPONENT(name, type) \
    ComponentArray *name##_array; \
    HASH_FIND_STR(world->component_arrays, #name, name##_array); \
    bool has_##name = name##_array && name##_array->enabled[entity_id]; \
    type *name = has_##name ? (type *)((char *)name##_array->array + name##_array->element_size * entity_id) : NULL; \
    execute_code = execute_code && has_##name;


void init_world(World *world);

Entity create_entity(World *world);

void add_component(World *world, Entity entity_id, const char *component_type, void *component_data);
