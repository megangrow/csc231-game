#include "sound.h"
#include "engine.h"

Sound::Sound(std::string name)
    : name{name} {}

void Sound::execute(Engine& engine) {
  engine.audio.play_sound(name);
}