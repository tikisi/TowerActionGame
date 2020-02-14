#include "Player.h"

void Player::upate() {
  // キー入力
  this->actionManager.update();
  
  ClearPrint();
  Print << static_cast<int>(actionManager.getState());
  
  // 移動
  this->physics.accel = actionManager.getAccel();
  this->physics.update();

  // 床との当たり判定
  if (this->physics.pos.y > Scene::CenterF().y - 1) {
    this->physics.pos.y = Scene::CenterF().y;
    this->physics.speed.y = 0;
    if (this->actionManager.getState() == ActionState::JUMP) {
      // ジャンプ中に床に当たった場合
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
