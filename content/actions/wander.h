#pragma once
#include "action.h"
#include "vec.h"

class Wander : public Action {
public:
  // Move to randomized open floor tile
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
};