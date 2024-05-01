#include "die.h"
#include "entity.h"
#include "engine.h"
#include "item.h"

Die::Die(Entity& entity)
  : entity{entity} {}

void Die::execute(Engine& engine) {
  engine.remove_entity(entity);

  // get item from entity
  Item dropped_item{*entity.get_current_item()};
  // place item on tile
  //dropped_item entity.get_position();

  //



}
