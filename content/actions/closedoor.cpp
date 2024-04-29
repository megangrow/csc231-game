#include "closedoor.h"
#include "entity.h"
#include "updatefov.h"
#include "sound.h"

Result CloseDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed_any_doors{false};
    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && tile.door->is_open()) {
            tile.door->close();
            std::make_shared<Sound>("door-close");
            closed_any_doors = true;
        }
    }
    if (closed_any_doors) {
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure(); //don't lose turn if no doors around
    }
}