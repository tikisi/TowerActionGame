#include "Player.h"

void Player::upate() {
  this->actionManager.update();
  ClearPrint();
  Print << static_cast<int>(actionManager.getState());
  
  this->physics.accel = actionManager.getAccel();

  this->physics.update();

  // °‚Æ‚Ì“–‚½‚è”»’è
  if (this->physics.pos.y > Scene::CenterF().y - 1) {
    this->physics.pos.y = Scene::CenterF().y;
    this->physics.speed.y = 0;
    if (this->actionManager.getState() == ActionState::JUMP) {
      this->actionManager.changeAction(ActionState::STAND);
    }
  }

}

void Player::draw() const {
  if (this->actionManager.getDir() == Direction::Right) {
    actionManager.getTexture().draw(physics.pos);
  } else {
    actionManager.getTexture().mirrored().draw(physics.pos);
  }
}
