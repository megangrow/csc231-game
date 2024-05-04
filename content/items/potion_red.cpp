#include "potion_red.h"
#include "engine.h"
#include "entity.h"
#include "heal.h"

RedPotion::RedPotion(int damage) //heals 2
    : Item{"potion_red"}, damage{damage} {
}

void RedPotion::use(Engine& engine, Entity& owner) {
  engine.events.create_event<Heal>(owner, -20);
  owner.remove_item(this);
}