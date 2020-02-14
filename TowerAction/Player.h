#pragma once
#include <Siv3D.hpp>
#include "ActionManager.h"
#include "Physics.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player {
 private:
  Physics physics;
  ActionManager<TextureRegion> actionManager;
  inline constexpr static float gravity = 0.2f;

  // ----キャラの状態-------

 public:
  Player() = default;
  ~Player() = default;

  Player(Vec2 position, Point textureSize = Point(64, 64),
         FilePath path = U"../Asset/UnityChan.png")
      : actionManager(path),
        physics(textureSize, position) {}

  void upate();

  void draw() const;
};
