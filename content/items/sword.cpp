#include "sword.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"

Sword::Sword(int damage)
    : Item{"sword"}, damage{damage} {}

// Classic item: thrust movement
void Sword::use(Engine& engine, Entity& attacker, Entity& defender) {
  engine.events.create_event<Thrust>(sprite, attacker.get_direction());
  engine.events.create_event<Hit>(defender, damage);
}
