#pragma once

#include <functional>
#include <memory>
#include <string>

#include "entity.h"
#include "sprite.h"

class Weapon {
public:
    Weapon();
    // name corresponds to a sprite in weapons.txt
    Weapon(std::string  name, int damage);
    virtual ~Weapon() = default;

    // override with what happens when the weapon is used in game
    virtual void use(Engine& engine, Entity& attacker, Entity& defender);

    // these are public to allow for manipulation by heroes and monsters
    std::string name;
    int damage{0};
    Sprite sprite;
};
