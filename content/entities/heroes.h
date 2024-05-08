#pragma once
#include <memory>
#include "entity.h"

namespace Heroes {
    // Sets sprite, health, inventory, behavior
    void make_wizard(std::shared_ptr<Entity>& hero);
    // Behavior links keypresses to actions
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity);
}
