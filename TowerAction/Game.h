#pragma once
#include <Siv3D.hpp>
#include "Common.h"
#include "Player.h"
#include "Block.h"

/// <summary>
/// ÉQÅ[ÉÄâÊñ 
/// </summary>
class Game : public App::Scene {
 private:
  Player player;
  Array<BaseBlock *> blocks;

 public:
  Game(const InitData &init) : IScene(init), player(Point(Scene::Center())) {
    blocks.push_back(new BaseBlock(200, Scene::Center().y));
  };

  void update() override;

  void draw() const override;
};
