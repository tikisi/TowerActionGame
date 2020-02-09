#include "Player.h"

void Player::upate() {
  // キー入力
  PlayerState nextState = PlayerState::STAND;
  // ジャンプ時
  if (state == PlayerState::JUMP) {
    if (jump()) {
      nextState = PlayerState::JUMP;
    } else {
      nextState = PlayerState::STAND;
    }
  }
  // ←キー
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
  // →キー
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
  // ←キー→キー同時押し時
  if (nextState == PlayerState::Walk && KeyRight.pressed() &&
      KeyLeft.pressed()) {
    nextState = PlayerState::STAND;
  }
  // spaceキー
  if (state != PlayerState::JUMP && KeySpace.down()) {
    nextState = PlayerState::JUMP;
  }

  // シーンに変更があった場合
  if (nextState != state) {
    state = nextState;
    animationManager.changeAnimation(state);
  }

  animationManager.update();

  // デバッグ用（地面についたら戻す)
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
  } else if (/*地面との当たり判定*/ Scene::CenterF().y <= position.y ||
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
