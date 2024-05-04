#pragma once
#include "item.h"
#include "engine.h"
#include "entity.h"

class Coin : public Item {
public:
  explicit Coin(int damage); // heals 2 health
private:
  int damage;
};