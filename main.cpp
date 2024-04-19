#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "entity.h"


int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_wizard(hero);

        for (int i = 0; i < 2; ++i) {
          std::shared_ptr<Entity> monster = engine.create_monster();
          Monsters::make_orc_masked(monster);
        }
        for (int i = 0; i < 2; ++i) {
          std::shared_ptr<Entity> monster = engine.create_monster();
          Monsters::make_skeleton(monster);
        }
        for (int i = 0; i < 2; ++i) {
          std::shared_ptr<Entity> monster = engine.create_monster();
          Monsters::make_zombie_small(monster);
        }


        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
