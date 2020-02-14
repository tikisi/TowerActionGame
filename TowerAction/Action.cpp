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
  if (KeyRight.pressed()) {
    this->dir = Direction::Right;
    changer->changeAction(ActionState::Walk);
  } else if (KeyLeft.pressed()) {
    this->dir = Direction::Left;
    changer->changeAction(ActionState::Walk);
  }
  // �A�j���[�V����
  if (this->frameCounter++ == 20) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 0;
  }
}

void WalkAction::update() {
  // ������
  accelVariation.x = 0.0f;

  // ��ԑJ��
  if (KeyZ.down()) {
    changer->changeAction(ActionState::JUMP);
    return;
  }
  // �L�[�𗣂����Ƃ�
  if (KeyRight.up()) {
    changer->changeAction(ActionState::STAND);
    this->accelVariation.x = -3.0f;
    return;
  } else if (KeyLeft.up()) {
    changer->changeAction(ActionState::STAND);
    this->accelVariation.x = 3.0f;
    return;
  }
  // �L�[�𓯎����������Ƃ�
  if ((KeyRight + KeyLeft).pressed()) {
    changer->changeAction(ActionState::STAND);
    // �����𔽓]
    dir = static_cast<Direction>(!bool(dir));
    // ���W�ړ�
    frameCounter = 0;
  }

  // �ړ�
  if (frameCounter == 0) {
    if (dir == Direction::Right) {
      this->accelVariation.x = 3.0f;
    } else {
      this->accelVariation.x = -3.0f;
    }
    frameCounter++;
  }

  // �A�j���[�V����
  if (this->frameCounter++ == 6) {
    if (++(this->index) == this->size) {
      this->index = 0;
    }
    frameCounter = 1;
  }
}

void JumpAction::update() {
  // �J�� �i�n�ʂƏՓ˂����Ƃ���player->actionManager->changer()����
  /*if (frameCounter == 60) {
    this->changer->changeAction(ActionState::STAND);
  }*/

  // �ړ�
  if (frameCounter == 0) {
    this->accelVariation.y = -6.0f;  // ����
  } else if (frameCounter < 30 && !KeyZ.pressed()) {
    this->accelVariation.y = 0.1;  // ����
  } else {
    this->accelVariation.y = 0.0f;  //�ʏ�
  }
  if (KeyRight.pressed()) {
    this->dir = Direction::Right;
    accelVariation.x = 3.0f;
  }
  if (KeyLeft.pressed()) {
    this->dir = Direction::Left;
    accelVariation.x = -3.0f;
  }

  // �A�j���[�V����
  if (this->frameCounter++ == 8) {
    if (this->index != this->size) {
      index++;
    }
    frameCounter = 0;
  }

  frameCounter++;
}
