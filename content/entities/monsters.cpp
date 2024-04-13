#include "monsters.h"

namespace Monsters {
    void make_ogre(std::shared_ptr<Entity>& hero) {
            hero->set_sprite("ogre");
            hero->set_max_health(10);
        }
}
