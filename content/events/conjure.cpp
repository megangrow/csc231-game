#include "conjure.h"

constexpr int duration = 5; // # of frames
constexpr int delta = 3; // pixels per frame

Conjure::Conjure(Sprite& sprite, Vec direction)
    :Event{duration}, sprite{sprite}, copy{sprite}, direction(direction) {
    sprite.center = sprite.size / 2;

    if (direction == Vec{1, 0}) { // RIGHT
      sprite.shift.y += sprite.size.y / 2;
      sprite.angle = 90;
    }
    else if (direction == Vec{-1, 0}) { // LEFT
      sprite.shift.y += sprite.size.y / 2;
      sprite.angle = -90;
    }
    else if (direction == Vec{0, 1}) { // UP
      sprite.angle = 0;
      this->direction = -1 * direction;
    }
    else { // DOWN
      sprite.angle = 180;
      sprite.shift.y += sprite.size.y;
      this->direction = -1 * direction;
    }

}

void Conjure::execute(Engine&) {
  //shift in pixels (16 per tile)
  sprite.angle += 180;

}
// reset
void Conjure::when_done(Engine&) {
  sprite = copy;
}