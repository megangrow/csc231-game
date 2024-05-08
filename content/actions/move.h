#pragma once
#include "action.h"
#include "vec.h"

class Move : public Action {
public:
    Move(Vec direction);
    // Perform function checks if tile is able to move onto
    // Returns alternatives of attacking or resting if entity is on tile,
    // opening door if door is closed, and picking up items from tiles
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
private:
    Vec direction;
};
