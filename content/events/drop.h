#pragma once

#include "event.h"
#include "entity.h"
#include "tile.h"

//forward declaration (declare the type) (speeding up compilation time)
class Item;

class Drop : public Event {
public:
  Drop(Entity& entity, Tile& tile, std::shared_ptr<Item> drop_item);
  // Allows entities to drop items on tiles when they die
  void execute(Engine& engine) override;
private:
  std::shared_ptr<Item> drop_item;
  Tile& tile;
  Entity& entity;
};
