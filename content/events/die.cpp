#include "die.h"
#include "entity.h"
#include "engine.h"

Die::Die(Entity& entity)
  : entity{entity} {}

void Die::execute(Engine& engine) {
  engine.remove_entity(entity);
}
