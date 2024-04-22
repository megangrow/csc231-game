#include "monsters.h"
#include "action.h"
#include "engine.h"
#include "rest.h"
#include "move.h"
#include "closedoor.h"
#include "opendoor.h"
#include "randomness.h"
#include "wander.h"
#include "sword.h"
#include "axe.h"

namespace Monsters {
    void make_ogre(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("ogre");
        monster->set_max_health(10);
        monster->add_to_inventory(std::make_shared<Axe>(7));
        monster->behavior = aggressive_behavior;

    }
    void make_orc_masked(std::shared_ptr<Entity>& monster) {
        monster->set_sprite("orc_masked");
        monster->set_max_health(12);
        monster->add_to_inventory(std::make_shared<Sword>(5));
        monster->behavior = aggressive_behavior;
    }
    void make_skeleton(std::shared_ptr<Entity>& monster) {
      monster->set_sprite("skeleton");
      monster->set_max_health(20);
      monster->behavior = passive_behavior;
    }
    void make_zombie_small(std::shared_ptr<Entity>& monster) {
      monster->set_sprite("zombie_small");
      monster->set_max_health(10);
      monster->behavior = aggressive_behavior;
    }

    std::unique_ptr<Action> aggressive_behavior(Engine& engine, Entity& entity) {
      // pursue Hero if monster can see him (If Hero sees me, I see him)
      if (entity.is_visible() && engine.hero) {
          auto path = engine.dungeon.calculate_path(entity.get_position(),
          engine.hero->get_position());
          if (path.size() > 1) {
              auto direction = path.at(1) - path.at(0);
              return std::make_unique<Move>(direction);
          }
      }
      // Monster doesn't see Hero
      if (probability(66)) {
          return std::make_unique<Wander>();
      }
      return std::make_unique<Rest>();
    }

    std::unique_ptr<Action> passive_behavior(Engine&, Entity&) {
      // Passive monsters just wander around to be a nuisance, they don't pursue hero
      if (probability(66)) {
        return std::make_unique<Wander>();
      }
      return std::make_unique<Rest>();
    }

}
