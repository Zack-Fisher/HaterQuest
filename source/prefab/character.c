#include "../prefab.h"

#include "../mover.h"
#include "../color.h"

Entity pPlayer(World* world, u8 px, u8 py) {
    Entity e = create_entity(&world);
    Position position2 = {px, py};
    add_component(&world, e, "Position", &position2);

    Mover mover = {'@', RGBA8(0xFF, 0x00, 0x00, 0xFF)}; 
    add_component(&world, e, "Mover", &mover);

    Controller controller = {1};
    add_component(&world, e, "Controller", &controller);

    return e;
}

Entity pGuy(World* world, u8 px, u8 py) {
    Entity e = create_entity(&world);
    Position position2 = {px, py};
    add_component(&world, e, "Position", &position2);

    Mover mover = {'@', RGBA8(0xFF, 0x00, 0x00, 0xFF)}; 
    add_component(&world, e, "Mover", &mover);

    return e;
}
