#include "staff_red.h"
#include "engine.h"
#include "hit.h"
#include "conjure.h"
#include "entity.h"
#include "animation.h"

StaffRed::StaffRed(int damage)
  : Item{"staff_red"}, damage{damage} {}

// Classic item: conjure movement, lightning animation on defender
void StaffRed::use(Engine& engine, Entity& attacker, Entity& defender) {
  Vec direction = defender.get_position() - attacker.get_position();
  auto swing = engine.events.create_event<Conjure>(sprite, direction);
  std::shared_ptr<Event> lightning = std::make_shared<Animation>("lightning", defender.get_position());
  lightning->add_next(Hit{defender, damage});
  swing->add_next(lightning);
}