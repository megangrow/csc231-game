#include "closedoor.h"
#include "entity.h"
#include "updatefov.h"
#include "sound.h"

Result CloseDoor::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    // Need to get all surrounding tiles with doors
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);
    bool closed_any_doors{false};
    for (Vec neighbor : neighbors) {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && tile.door->is_open()) {
          // closes the door on the tile if open
            tile.door->close();
            // Add audio for door closing
            std::make_shared<Sound>("door-close");
            closed_any_doors = true;
        }
    }
    if (closed_any_doors) {
        // Updates field of view for hero to gray out rooms behind
        // closed doors
        engine.events.create_event<UpdateFOV>();
        return success();
    }
    else {
        return failure(); // Don't lose turn if there are no doors around
    }
}