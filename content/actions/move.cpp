#include "rest.h"
#include "move.h"
#include <memory>
#include "entity.h"
#include <iostream>
#include "engine.h"
#include "opendoor.h"
#include "updatefov.h"
#include "attack.h"

Move::Move(Vec direction)
    : direction{direction} {}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);

    Vec position = entity->get_position() + direction;
    Tile& tile = engine.dungeon.get_tile(position);

    if (tile.has_door() && !tile.door->is_open()) {
      return alternative(OpenDoor{*tile.door});
    }
    if (tile.is_wall()) {
        return failure();
    }
    if (tile.has_entity()) {
        if (entity->get_team() != tile.entity->get_team()) {
          return alternative(Attack(*tile.entity));
        }
        else {
          return alternative(Rest{});
        }
    }
    entity->move_to(position);
    return success();
}
