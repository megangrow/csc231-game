#include "conjure.h"

constexpr int duration = 5; // # of frames
constexpr int delta = 3; // pixels per frame

Conjure::Conjure(Sprite& sprite, Vec direction)
    :Event{duration}, sprite{sprite}, copy{sprite}, direction(direction) {
    sprite.center = sprite.size / 2;

    // These if statements set the starting position of this animation

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
  // Shift in pixels (16 per tile)
  // This causes the weapon to spin around in a "conjure-like" motion
  sprite.angle += 180;

}

void Conjure::when_done(Engine&) {
  // Reset weapon when done
  sprite = copy;
}