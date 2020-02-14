#include "Player.h"

void Player::upate() {
  this->actionManager.update();
  
  // ��������
    // �d�͂�������
  //this->physics.accel.y = this->gravity;
    // �����蔻�� -> �V�[���؂�ւ�
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
