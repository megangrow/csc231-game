#include "heroes.h"
#include "action.h"
#include "engine.h"
#include "rest.h"
#include "move.h"

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
        } else if (key == "W") {
            return std::make_unique<Move>();
        }
        return nullptr;
    }

}
