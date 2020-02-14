#include "Action.h"
#include <string>

void Action::initialize() {
  this->frameCounter = 0;
  this->index = 0;
  this->accelVariation = Vec2(0, 0);
}

/// <summary>
/// 現在のアニメーションのインデックスを取得
/// </summary>
/// <returns>index</returns>
size_t Action::getIndex() const { return this->index; }

/// <summary>
/// 加速度の変化量を取得
/// </summary>
/// <returns>加速度の変化量</returns>
Vec2 Action::getAccel() const { return this->accelVariation; }

Direction Action::getDir() const { return this->dir; }

void StandAction::update() {
  // 状態遷移
  if (KeyZ.down()) {
    this->changer->changeAction(ActionState::JUMP);
  }
  if (KeyRight.pressed() && !KeyLeft.pressed()) {
    this->dir = Direction::Right;
    changer->changeAction(ActionState::Walk);
    return;
  }
  if (!KeyRight.pressed() && KeyLeft.pressed()) {
    this->dir = Direction::Left;
    changer->changeAction(ActionState::Walk);
    return;
  }

  // アニメーション
  if (this->frameCounter++ == 20) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

WalkAction::WalkAction(ActionChanger* changer, size_t size, Direction dir)
    : Action(changer, size, dir) {
  if (dir == Direction::Right) {
    this->accelVariation.x = 1.0f;
  } else {
    this->accelVariation.x = -1.0f;
  }
}

void WalkAction::update() {
  // 遷移
  if (KeyZ.down()) {
    this->changer->changeAction(ActionState::JUMP);
  }
  if ((KeyRight.pressed() && KeyLeft.pressed()) ||
      (!KeyRight.pressed() && !KeyLeft.pressed())) {
    changer->changeAction(ActionState::STAND);
    return;
  }

  // アニメーション
  if (this->frameCounter++ == 5) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

void JumpAction::update() {
  // 遷移 （地面と衝突したときはplayer->actionManager->changer()から
  /*if (frameCounter == 60) {
    this->changer->changeAction(ActionState::STAND);
  }*/

  // 移動
  if (frameCounter == 0) {
    this->accelVariation.y = -20.0f;  // 初速
    this->frameCounter++;
  } else if (frameCounter < 30 && !KeyZ.pressed()) {
    this->accelVariation.y = 0.1;  // 減速
  } else {
    this->accelVariation.y = 0.0f;  //通常
  }

  if ((KeyRight.pressed() && KeyLeft.pressed()) ||
      (!KeyRight.pressed() && !KeyLeft.pressed())) {
    accelVariation.x = 0.0f;
  } else if (KeyRight.pressed()) {
    this->dir = Direction::Right;
    accelVariation.x = 1.0f;
  } else if (KeyLeft.pressed()) {
    this->dir = Direction::Left;
    accelVariation.x = -1.0f;
  }

  // アニメーション
  if (this->frameCounter++ == 9) {
    if (++(this->index) == this->size) {
      index-=2;
    }
    frameCounter = 1;
  }
}
