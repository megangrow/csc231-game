#include "swing.h"
#include <cmath>

// Animation code provided by Dr. Brown

constexpr int duration = 3;

Swing::Swing(Sprite& sprite, Vec direction)
    :Event{duration}, sprite{sprite}, copy{sprite}, starting_angle{sprite.angle} {
  // Based on direction, set starting angle
  if (direction == Vec{1, 0}) {
        starting_angle = 0;
        delta = 135.0 / (duration - 1);
    }
    else if (direction == Vec{-1, 0}) {
        starting_angle = 0;
        delta = -135.0 / (duration - 1);
    }
    else if (direction == Vec{0, 1}) {
        sprite.shift.y -= 12;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = -75 * sign;
        delta = 90.0 / (duration - 1) * sign;
    }
    else {
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 135 * sign;
        delta = 90.0 / (duration - 1) * sign;
    }
}

void Swing::execute(Engine&) {
  // Performs swinging animation
    sprite.angle = starting_angle + delta * frame_count;
}

void Swing::when_done(Engine&) {
  // Resets sprite to initial position
    sprite = copy;
}

