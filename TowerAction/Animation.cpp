#include "Animation.h"

void Animation::initialize() {
  this->frameCounter = 0;
  this->index = 0;
}

size_t Animation::getIndex() const {
  return this->index;
}

void StandAnimation::update() {
  if (this->frameCounter++ == 20) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

void WalkAnimation::update() {
  if (this->frameCounter++ == 15) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}
