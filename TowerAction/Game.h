#pragma once
#include "Common.h"

/**
 * @class Game
 * �Q�[�����
 */
class Game : public App::Scene {
 private:
 public:
  Game(const InitData &init) : IScene(init){};

  void update() override;

  void draw() const override;
};
