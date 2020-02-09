#include "Player.h"

void Player::upate() {
  // �L�[����
  PlayerState nextState = PlayerState::STAND;
  // �W�����v��
  if (state == PlayerState::JUMP) {
    if (jump()) {
      nextState = PlayerState::JUMP;
    } else {
      nextState = PlayerState::STAND;
    }
  }
  // ���L�[
  if (KeyLeft.pressed()) {
    this->direction = Direction::Left;
    if (nextState == PlayerState::STAND) {
      nextState = PlayerState::Walk;
      this->position.moveBy(-3, 0);
    } else if (nextState == PlayerState::Walk ||
               nextState == PlayerState::JUMP) {
      this->position.moveBy(-3, 0);
    }
  }
  // ���L�[
  if (KeyRight.pressed()) {
    this->direction = Direction::Right;
    if (nextState == PlayerState::STAND) {
      nextState = PlayerState::Walk;
      this->position.moveBy(3, 0);
    } else if (nextState == PlayerState::Walk ||
               nextState == PlayerState::JUMP) {
      this->position.moveBy(3, 0);
    }
  }
  // ���L�[���L�[����������
  if (nextState == PlayerState::Walk && KeyRight.pressed() &&
      KeyLeft.pressed()) {
    nextState = PlayerState::STAND;
  }
  // space�L�[
  if (state != PlayerState::JUMP && KeySpace.down()) {
    nextState = PlayerState::JUMP;
  }

  // �V�[���ɕύX���������ꍇ
  if (nextState != state) {
    state = nextState;
    animationManager.changeAnimation(state);
  }

  animationManager.update();

  // �f�o�b�O�p�i�n�ʂɂ�����߂�)
  if (position.y > Scene::CenterF().y) {
    position.y = Scene::CenterF().y;
  }
}

void Player::draw() const {
  if (this->direction == Direction::Right) {
    animationManager.getTexture().draw(position);
  } else {
    animationManager.getTexture().mirrored().draw(position);
  }
}

bool Player::jump() {
  if (jumpCounter == 0) {
    this->speed = speed0;
  } else if (/*�n�ʂƂ̓����蔻��*/ Scene::CenterF().y <= position.y ||
             jumpCounter == 60) {
    this->jumpCounter = 0;
    return false;
  }

  if (!KeySpace.pressed() && speed < 0) {
    this->speed *= 0.9f;
  }

  this->speed += gravity;
  this->position.y += speed;

  jumpCounter++;
  return true;
}
