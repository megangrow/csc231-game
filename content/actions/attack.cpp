#include "attack.h"
#include "entity.h"
#include "item.h"
#include "hit.h"
#include "engine.h"
#include "events.h"

Attack::Attack(Entity& defender) // Constructor
      : defender{defender} {}

Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    // get item of attacker and set it as the weapon to be used
    std::shared_ptr<Item> weapon = attacker->get_current_item();
    // use the weapon on the defender
    weapon->use(engine, *attacker, defender);
    return success();
}