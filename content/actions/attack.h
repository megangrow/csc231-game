#pragma once
#include "action.h"

class Attack : public Action {
public:
  Attack(Entity& defender);
  // Use weapon
  Result perform(Engine& engine, std::shared_ptr<Entity> attacker) override;
private:
  Entity& defender;
};