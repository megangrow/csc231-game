#include "opendoor.h"
#include "door.h"
#include "engine.h"
#include "updatefov.h"
#include "sound.h"

OpenDoor::OpenDoor(Door& door)
    : door{door} {}

Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    // Updating field of view allows entity to see into room
    engine.events.create_event<UpdateFOV>();
    door.open();
    // Audio
    std::make_shared<Sound>("door-open");
    return success();
}
