#include "Player.h"

void Player::upate() {
  this->actionManager.update();
  
  // 物理処理
    // 重力をかける
  //this->physics.accel.y = this->gravity;
    // 当たり判定 -> シーン切り替え
  // this->actionManager.changeAnimation();
  
  this->physics.accel = actionManager.getAccel();

  this->physics.update();
}

void Player::draw() const {
  if (this->actionManager.getDir() == Direction::Right) {
    actionManager.getTexture().draw(physics.pos);
  } else {
    actionManager.getTexture().mirrored().draw(physics.pos);
  }
}
