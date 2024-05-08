#include "bite.h"
#include "engine.h"

Bite::Bite(int damage)
    :Item{"none"} {}

void Bite::use(Engine& engine, Entity&, Entity& defender) {
 // Default attack pre-creation of others
 // Unused in this code
}
