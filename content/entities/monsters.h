#pragma once
#include <memory>
#include "entity.h"

namespace Monsters {
    // Aggresive behavior monsters
    void make_ogre(std::shared_ptr<Entity>& monster);
    void make_orc_masked(std::shared_ptr<Entity>& monster);
    void make_zombie_small(std::shared_ptr<Entity>& monster);
    void make_demon_big(std::shared_ptr<Entity>& monster);
    void make_necromancer(std::shared_ptr<Entity>& monster);

    // Passive behavior monsters
    void make_skeleton(std::shared_ptr<Entity>& monster);
    void make_muddy(std::shared_ptr<Entity>& monster);

    std::unique_ptr<Action> aggressive_behavior(Engine&, Entity&);
    std::unique_ptr<Action> passive_behavior(Engine&, Entity&);
}
