#include "Animation.h"
#include <string>

void Animation::initialize() {
  this->frameCounter = 0;
  this->index = 0;
}

/// <summary>
/// 現在のアニメーションのインデックスを取得
/// </summary>
/// <returns>index</returns>
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
  if (this->frameCounter++ == 5) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

void JumpAnimation::update() {
  if (this->frameCounter++ == 8) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}
