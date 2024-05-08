#pragma once
#include "action.h"

class Rest : public Action {
public:
  // Rest is essentially a skip turn
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
};
