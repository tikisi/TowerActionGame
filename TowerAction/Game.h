#pragma once
#include "Common.h"

/**
 * @class Game
 * ƒQ[ƒ€‰æ–Ê
 */
class Game : public App::Scene {
 private:
 public:
  Game(const InitData &init) : IScene(init){};

  void update() override;

  void draw() const override;
};
