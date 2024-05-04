#include "die.h"
#include "entity.h"
#include "engine.h"
#include "item.h"
#include "drop.h"

Die::Die(Entity& entity)
  : entity{entity} {}

void Die::execute(Engine& engine) {
  engine.remove_entity(entity);
  engine.events.create_event<Drop>(entity, engine.dungeon.get_tile(entity.get_position()), entity.get_current_item());
}
