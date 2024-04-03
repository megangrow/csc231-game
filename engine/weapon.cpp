#include "weapon.h"

#include <utility>

Weapon::Weapon()
    :name{}, damage{0} {}

Weapon::Weapon(std::string name, int damage)
    :name{std::move(name)}, damage{damage} {}


void Weapon::use(Engine&, Entity&, Entity&) {}
