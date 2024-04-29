#pragma once
#include "item.h"
#include "engine.h"
#include "entity.h"

class RedPotion : public Item {
public:
  explicit RedPotion(int damage); // heals 2 health
  void use(Engine& engine, Entity&, Entity& defender) override;
private:
  int damage;
};