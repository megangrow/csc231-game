#include "heroes.h"
#include "action.h"
#include "closedoor.h"
#include "engine.h"
#include "entity.h"
#include "heal.h"
#include "move.h"
#include "potion_red.h"
#include "rest.h"
#include "staff_green.h"
#include "staff_red.h"
#include "sword.h"
#include "drop.h"

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("wizard");
        hero->set_max_health(25);
        hero->add_to_inventory(std::make_shared<Sword>(4));
        hero->behavior = behavior;
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity& entity) {
        std::string key = engine.input.get_last_keypress();
        if (!key.empty() && std::isdigit(key.at(0))) {
          int item_num = std::stoi(key) - 1;
          entity.select_item(item_num);
        }
        if (key == "U" && entity.get_current_item()->name == "potion_red") {
          entity.get_current_item()->use(engine, entity);
          return nullptr;
        }
        if (key == "R") {
            return std::make_unique<Rest>();
        }
        if (key == "W") {
            return std::make_unique<Move>(Vec{0, 1});
        }
        if (key == "A") {
            return std::make_unique<Move>(Vec{-1, 0});
        }
        if (key == "S") {
            return std::make_unique<Move>(Vec{0, -1});
        }
        if (key == "D") {
            return std::make_unique<Move>(Vec{1, 0});
        }
        if (key == "C") {
            return std::make_unique<CloseDoor>();
        }
        return nullptr;
    }

}
