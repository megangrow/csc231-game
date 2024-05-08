#include "move.h"
#include "attack.h"
#include "engine.h"
#include "entity.h"
#include "item.h"
#include "opendoor.h"
#include "rest.h"
#include "updatefov.h"
#include <iostream>
#include <memory>

int coin_counter{0};

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
          // This is here so entities don't attack their teammates
          return alternative(Rest{});
        }
    }

    // Addition for final! Win condition:
    // If the coin is picked up, it increments the counter
    // If the counter reaches 10, game closes and print to terminal "YOU WIN"
    if (tile.has_item()) {
      if (tile.item->name == "coin") {
        ++coin_counter;
        if (coin_counter == 10) {
          std::cout << "YOU WIN";
          engine.stop();
        }
      }
      // If the item isn't a coin, add to inventory as usual
      if (tile.item->name != "coin") {
        entity->add_to_inventory(tile.item);
      }
      tile.item.reset(); // Erases the item from the tile once picked up
      engine.camera.update();
    }
    entity->move_to(position);
    return success();
}
