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
  if (KeyRight.pressed()) {
    this->dir = Direction::Right;
    changer->changeAction(ActionState::Walk);
  } else if (KeyLeft.pressed()) {
    this->dir = Direction::Left;
    changer->changeAction(ActionState::Walk);
  }
  // アニメーション
  if (this->frameCounter++ == 20) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

void WalkAction::update() {
  // 初期化
  accelVariation.x = 0.0f;

  // 状態遷移
  if (KeyZ.down()) {
    changer->changeAction(ActionState::JUMP);
    return;
  }
  // キーを離したとき
  if (KeyRight.up()) {
    changer->changeAction(ActionState::STAND);
    this->accelVariation.x = -3.0f;
    return;
  } else if (KeyLeft.up()) {
    changer->changeAction(ActionState::STAND);
    this->accelVariation.x = 3.0f;
    return;
  }
  // キーを同時押ししたとき
  if ((KeyRight + KeyLeft).pressed()) {
    changer->changeAction(ActionState::STAND);
    // 方向を反転
    dir = static_cast<Direction>(!bool(dir));
    // 座標移動
    frameCounter = 0;
  }

  // 移動
  if (frameCounter == 0) {
    if (dir == Direction::Right) {
      this->accelVariation.x = 3.0f;
    } else {
      this->accelVariation.x = -3.0f;
    }
    frameCounter++;
  }

  // アニメーション
  if (this->frameCounter++ == 6) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 1;
  }
}

void JumpAction::update() {
  // 遷移 （地面と衝突したときはplayer->actionManager->changer()から
  /*if (frameCounter == 60) {
    this->changer->changeAction(ActionState::STAND);
  }*/

  // 移動
  if (frameCounter == 0) {
    this->accelVariation.y = -6.0f;  // 初速
  } else if (frameCounter < 30 && !KeyZ.pressed()) {
    this->accelVariation.y = 0.1;  // 減速
  } else {
    this->accelVariation.y = 0.0f;  //通常
  }
  if (KeyRight.pressed()) {
    this->dir = Direction::Right;
    accelVariation.x = 3.0f;
  }
  if (KeyLeft.pressed()) {
    this->dir = Direction::Left;
    accelVariation.x = -3.0f;
  }

  // アニメーション
  if (this->frameCounter++ == 8) {
    if (this->index != this->size) {
      index++;
    }
    frameCounter = 0;
  }

  frameCounter++;
}
