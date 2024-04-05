#pragma once

#include "item.h"

class Bite : public Item {
public:
    explicit Bite(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;
};
    
