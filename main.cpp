#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "entity.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        // Create hero character
        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_wizard(hero);

        // Create monsters

        std::shared_ptr<Entity> monster = engine.create_monster();
        Monsters::make_ogre(monster);

        std::shared_ptr<Entity> monster2 = engine.create_monster();
        Monsters::make_necromancer(monster2);

        std::shared_ptr<Entity> monster5 = engine.create_monster();
        Monsters::make_demon_big(monster5);

        for (int i = 0; i < 3; ++i) {
          std::shared_ptr<Entity> monster3 = engine.create_monster();
          Monsters::make_orc_masked(monster3);
        }
        for (int i = 0; i < 15; ++i) {
          std::shared_ptr<Entity> monster4 = engine.create_monster();
          Monsters::make_skeleton(monster4);
        }
        for (int i = 0; i < 5; ++i) {
          std::shared_ptr<Entity> monster6 = engine.create_monster();
          Monsters::make_zombie_small(monster6);
          std::shared_ptr<Entity> monster7 = engine.create_monster();
          Monsters::make_muddy(monster7);
        }


        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
