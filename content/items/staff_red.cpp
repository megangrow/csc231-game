#include "staff_red.h"
#include "engine.h"
#include "hit.h"

StaffRed::StaffRed(int damage)
  : Item{"staff_red"}, damage{damage} {}

void StaffRed::use(Engine& engine, Entity&, Entity& defender) {
  engine.events.create_event<Hit>(defender, damage);
}