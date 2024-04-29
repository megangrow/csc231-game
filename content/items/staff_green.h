#pragma once
#include "item.h"

class StaffGreen : public Item {
public:
  explicit StaffGreen(int damage);
  void use(Engine& engine, Entity&, Entity& defender) override;
private:
  int damage;

};
