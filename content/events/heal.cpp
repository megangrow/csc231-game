#include "heal.h"
#include "entity.h"
#include "die.h"

Heal::Heal(Entity& entity, int damage)
    : entity{entity}, damage{damage} {}

void Heal::execute(Engine&) {
  entity.take_damage(damage);
}

void Heal::when_done(Engine& engine) {
  if (!entity.is_alive()) {
    add_next(Die{entity});
  }
}