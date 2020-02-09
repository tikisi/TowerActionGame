#include "Player.h"

void Player::upate() {

  animationManager.update();

  if (KeyRight.pressed()) {
    this->position.moveBy(Point(3, 0));
  }
  if (KeyLeft.pressed()) {
    this->position.moveBy(Point(-3, 0));
  }
  if (KeySpace.down()) {
    this->state = PlayerState::JUMP;
  }

  // -----JUMPŠm”F--------
  /*
  static int jumpCounter = 0;
  if (this->state == PlayerState::JUMP) {
    this->position.moveBy(
        Point(0, -int(10 * (1.0 / 180) * 1_pi * cos((1.0 / 180) * 1_pi * jumpCounter++))));
    if (jumpCounter == 60) {
      jumpCounter = 0;
      this->state = PlayerState::STAND;
    }
  }*/
}

void Player::draw() const { animationManager.getTexture().draw(position); }

