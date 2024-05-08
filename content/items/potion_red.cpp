#include "potion_red.h"
#include "engine.h"
#include "entity.h"
#include "heal.h"

RedPotion::RedPotion(int damage) //heals 2
    : Item{"potion_red"}, damage{damage} {
}

// Health item: no movement
void RedPotion::use(Engine& engine, Entity& owner) {
  // Allows user to use to heal themselves
  engine.events.create_event<Heal>(owner, -20);
  // Addition for final!
  // Removes potion from inventory after use
  owner.remove_item(this);
}