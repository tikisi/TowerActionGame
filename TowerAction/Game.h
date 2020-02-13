#pragma once
#include "Common.h"
#include "Player.h"

/// <summary>
/// ƒQ[ƒ€‰æ–Ê
/// </summary>
class Game : public App::Scene {
 private:
  Player player;

 public:
  Game(const InitData &init) : IScene(init), player(Point(Scene::Center())) {};

  void update() override;

  void draw() const override;
};
