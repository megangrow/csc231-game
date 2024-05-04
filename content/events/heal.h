#pragma once
#include "event.h"

//forward declaration (declare the type) (speeding up compilation time)
class Entity;

class Heal : public Event {
public:
  Heal(Entity& entity, int damage);
  void execute(Engine& engine) override;
  void when_done(Engine& engine) override;
private:
  Entity& entity;
  int damage;
};
