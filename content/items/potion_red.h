#pragma once
#include "item.h"
#include "engine.h"
#include "entity.h"

class RedPotion : public Item {
public:
  explicit RedPotion(int damage);
  // This item heals the owner, rather than damage the defender
  // One time use
  virtual void use(Engine& engine, Entity& owner) override;
private:
  int damage;
};