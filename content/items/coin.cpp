#include "coin.h"
#include "engine.h"
#include "entity.h"
#include "heal.h"

Coin::Coin(int damage)
    : Item{"coin"}, damage{damage} {
  // Creates coin objects
}
