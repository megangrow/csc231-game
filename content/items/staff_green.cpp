#include "staff_green.h"
#include "animation.h"
#include "engine.h"
#include "entity.h"
#include "hit.h"
#include "swing.h"

StaffGreen::StaffGreen(int damage)
    : Item{"staff_green"}, damage{damage} {}

void StaffGreen::use(Engine& engine, Entity& attacker, Entity& defender) {
  Vec direction = defender.get_position() - attacker.get_position();

  auto swing = engine.events.create_event<Swing>(sprite, direction);
  std::shared_ptr<Event> fire = std::make_shared<Animation>("fire", defender.get_position());
  fire->add_next(Hit{defender, damage});
  swing->add_next(fire);
}
