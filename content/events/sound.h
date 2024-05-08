#pragma once

#include "event.h"
#include "engine.h"

class Sound : public Event {
public:
  explicit Sound(std::string name);
  void execute(Engine& engine) override;

private:
  std::string name;
};