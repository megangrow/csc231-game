#include "heroes.h"
#include "action.h"
#include "engine.h"
#include "rest.h"
#include "move.h"
#include "closedoor.h"
#include "opendoor.h"

namespace Heroes {
    void make_wizard(std::shared_ptr<Entity>& hero) {
        hero->set_sprite("wizard");
        hero->set_max_health(10);
        hero->behavior = behavior;
    }
    std::unique_ptr<Action> behavior(Engine& engine, Entity&) {
        std::string key = engine.input.get_last_keypress();
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
