#include "axe.h"
#include "engine.h"
#include "hit.h"

Axe::Axe(int damage)
    : Item{"axe"}, damage{damage} {}

void Axe::use(Engine& engine, Entity&, Entity& defender) {
  engine.events.create_event<Hit>(defender, damage);
}