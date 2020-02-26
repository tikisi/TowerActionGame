#include "Player.h"

void Player::upate() {
  // �L�[����
  this->actionManager.update();

  ClearPrint();
  Print << static_cast<int>(actionManager.getState());

  // �ړ�
  this->physics.accel = actionManager.getAccel();
  this->physics.update();

  // ���Ƃ̓����蔻��
  if (this->physics.pos.y > Scene::CenterF().y - 1) {
    this->physics.pos.y = (float)Scene::CenterF().y;
    this->physics.speed.y = 0;
    if (this->actionManager.getState() == ActionState::JUMP) {
      // �W�����v���ɏ��ɓ��������ꍇ
      this->actionManager.setNextAction(ActionState::STAND);
    }
  }
}

void Player::draw() const {
  if (this->actionManager.getDir() == Direction::Right) {
    actionManager.getTexture().draw(physics.pos);
  } else {
    actionManager.getTexture().mirrored().draw(physics.pos);
  }
  RectF(physics.pos, physics.size).drawFrame(1, 1, Palette::Red);
}

void Player::collisionWithBlock(const BaseBlock &block) {
  // �W�����v���ɏ��ɓ��������ꍇ
  if(this->physics.collision(block) == Physics::Edge::cd && this->actionManager.getState() == ActionState::JUMP) {
      this->actionManager.setNextAction(ActionState::STAND); 
  }
}
