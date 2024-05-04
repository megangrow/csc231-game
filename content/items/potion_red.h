#pragma once
#include "item.h"
#include "engine.h"
#include "entity.h"

class RedPotion : public Item {
public:
  explicit RedPotion(int damage);
  virtual void use(Engine& engine, Entity& owner) override;
private:
  int damage;
};