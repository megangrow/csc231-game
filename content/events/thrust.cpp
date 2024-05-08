#include "thrust.h"

constexpr int duration = 3; // # of frames
constexpr int delta = 3; // pixels per frame

Thrust::Thrust(Sprite& sprite, Vec direction)
      :Event{duration}, sprite{sprite}, copy{sprite}, direction(direction) {
    // Orients the weapon
    sprite.center = sprite.size / 2;
    sprite.shift.y -= sprite.size.y / 4;

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

void Thrust::execute(Engine&) {
  // Shift in pixels (16 per tile)
  // Moves weapon forward
  sprite.shift += direction * delta;
}

void Thrust::when_done(Engine&) {
  // Resets to initial position (retract thrust)
  sprite = copy;
}