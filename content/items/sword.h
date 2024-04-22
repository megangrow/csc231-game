#pragma once
#include "item.h"
#include "engine.h"
#include "entity.h"

class Sword : public Item {
public:
  explicit Sword(int damage);
  void use(Engine& engine, Entity&, Entity& defender) override;
private:
  int damage;
};