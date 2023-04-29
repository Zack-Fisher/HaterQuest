#include "../prefab.h"

#include "../mover.h"
#include "../ui.h"

Entity pHello(World* world, u8 px, u8 py) {
    Entity e = create_entity(&world);
    Position p = {px, py};
    add_component(&world, e, "Position", &p);

    Label label = {"Hello World!"};
    add_component(&world, e, "Label", &label);

    return e;
}

Entity pSign(World* world, u8 px, u8 py, char* text) {
    Entity e = create_entity(&world);
    Position p = {px, py};
    add_component(&world, e, "Position", &p);

    Label label = {text};
    add_component(&world, e, "Label", &label);

    return e;
}