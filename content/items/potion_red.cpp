#include "potion_red.h"
#include "engine.h"
#include "hit.h"
#include "thrust.h"
#include "entity.h"

RedPotion::RedPotion(int damage) //heals 2
    : Item{"potion_red"}, damage{damage} {}

void RedPotion::use(Engine& engine, Entity& attacker, Entity&) {
  engine.events.create_event<Hit>(attacker, damage);
}
