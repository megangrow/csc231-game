#include "rest.h"
#include "move.h"
#include <memory>
#include "entity.h"
#include <iostream>
#include "engine.h"

Move::Move(Vec direction)
    : direction{direction} {}

Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity){
    entity->change_direction(direction);
    Vec tile_go = entity->get_position() + direction;
    if (engine.dungeon.get_tile(tile_go).walkable) {
        entity->move_to(tile_go);
        return success();
    }
    return failure();
}
