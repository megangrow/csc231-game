#pragma once
#include "item.h"
#include "entity.h"
#include "engine.h"

class Axe : public Item {
public:
  explicit Axe(int damage);
  void use(Engine& engine, Entity&, Entity& defender) override;
private:
  int damage;
};