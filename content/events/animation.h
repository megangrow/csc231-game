#pragma once

#include "event.h"
#include "vec.h"
#include "animatedsprite.h"

// Basic class for all animations used

class Animation : public Event {
public:
  explicit Animation(std::string name, Vec position);
  void execute(Engine & engine) override;

private:
  std::string name;
  Vec position;
  AnimatedSprite sprite;
};