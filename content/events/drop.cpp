#include "drop.h"
#include "item.h"
#include "engine.h"
#include "entity.h"

Drop::Drop(Entity& entity, Tile& tile, std::shared_ptr<Item> drop_item)
  : entity{entity}, tile{tile}, drop_item{drop_item} { }

void Drop::execute(Engine& engine) {
  tile.item = drop_item;
}