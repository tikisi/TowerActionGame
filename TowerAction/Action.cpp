#include "Action.h"
#include <string>

void Action::initialize() {
  this->frameCounter = 0;
  this->index = 0;
  this->accelVariation = Vec2(0, 0);
}

/// <summary>
/// ���݂̃A�j���[�V�����̃C���f�b�N�X���擾
/// </summary>
/// <returns>index</returns>
size_t Action::getIndex() const { return this->index; }

/// <summary>
/// �����x�̕ω��ʂ��擾
/// </summary>
/// <returns>�����x�̕ω���</returns>
Vec2 Action::getAccel() const { return this->accelVariation; }

Direction Action::getDir() const { return this->dir; }

void StandAction::update() {
  // ��ԑJ��
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

  // �A�j���[�V����
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
  // �J��
  if (KeyZ.down()) {
    this->changer->changeAction(ActionState::JUMP);
  }
  if ((KeyRight.pressed() && KeyLeft.pressed()) ||
      (!KeyRight.pressed() && !KeyLeft.pressed())) {
    changer->changeAction(ActionState::STAND);
    return;
  }

  // �A�j���[�V����
  if (this->frameCounter++ == 5) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

void JumpAction::update() {
  // �J�� �i�n�ʂƏՓ˂����Ƃ���player->actionManager->changer()����
  /*if (frameCounter == 60) {
    this->changer->changeAction(ActionState::STAND);
  }*/

  // �ړ�
  if (frameCounter == 0) {
    this->accelVariation.y = -20.0f;  // ����
    this->frameCounter++;
  } else if (frameCounter < 30 && !KeyZ.pressed()) {
    this->accelVariation.y = 0.1;  // ����
  } else {
    this->accelVariation.y = 0.0f;  //�ʏ�
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

  // �A�j���[�V����
  if (this->frameCounter++ == 9) {
    if (++(this->index) == this->size) {
      index-=2;
    }
    frameCounter = 1;
  }
}
