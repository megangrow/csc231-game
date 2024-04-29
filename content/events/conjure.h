#pragma once

#include "sprite.h"
#include "vec.h"
#include "event.h"

class Conjure : public Event {
public:
  Conjure(Sprite& sprite, Vec direction);

  void execute(Engine& engine) override; //sprite.shift += (dx, dy)
  void when_done(Engine& engine) override; //reset

private:
  Sprite& sprite; //original weapon sprite
  Sprite copy; //copy so we can reset after animation
  Vec direction; //direction to shift
};