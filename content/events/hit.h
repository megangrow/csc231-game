#pragma once
#include "event.h"

//forward declaration (declare the type) (speeding up compilation time)
class Entity;

class Hit : public Event {
public:
  Hit(Entity& entity, int damage);
  // Causes entity to take damage
  void execute(Engine& engine) override;
  // Checks if entity is alive, if not removes from game
  void when_done(Engine& engine) override;
private:
  Entity& entity;
  int damage;
};
