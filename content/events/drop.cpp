#include "drop.h"
#include "item.h"
#include "engine.h"
#include "entity.h"

Drop::Drop(Entity& entity, Tile& tile, std::shared_ptr<Item> drop_item)
  : entity{entity}, tile{tile}, drop_item{drop_item} { }

void Drop::execute(Engine& engine) {
  // Places item to be dropped on tile that entity is on
  // Since this occurs only during death, the entity is removed so there is no
  // interference between where the item is dropped and any live entities
  tile.item = drop_item;
}