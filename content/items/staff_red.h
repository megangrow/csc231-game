#pragma once
#include "item.h"

class StaffRed : public Item {
public:
  explicit StaffRed(int damage);
  void use(Engine& engine, Entity&, Entity& defender) override;
private:
  int damage;

};
