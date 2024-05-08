#pragma once
#include "event.h"

class Entity;

class Die : public Event {
public:
  explicit Die(Entity& entity);
  // Removes entity from game (if entity is hero, game ends)
  // Drops current item onto current tile
  void execute(Engine& engine) override;
private:
  Entity& entity;
};
