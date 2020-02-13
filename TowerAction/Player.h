#pragma once
#include <Siv3D.hpp>
#include "AnimationManager.h"

/// <summary>
/// プレイヤークラス
/// </summary>
class Player {
  enum class Direction { Right, Left };

 private:
  Point textureSize;
  AnimationManager<TextureRegion> animationManager;

  // ----キャラの状態-------
  Vec2 position;
  PlayerState state;
  Direction direction;

 public:
  Player() = default;
  ~Player() = default;

  Player(Vec2 position, Point textureSize = Point(64, 64),
         FilePath path = U"../Asset/UnityChan.png")
      : position(position), animationManager(path), textureSize(textureSize) {
    this->state = PlayerState::STAND;
    this->direction = Direction::Right;
    this->jumpCounter = 0;

    this->speedY = speed0;
  }

  void upate();

  void draw() const;

  // jump用変数
 private:
  float speedY;
  inline constexpr static float gravity = 0.2f;
  inline constexpr static float speed0 = -6.0f;
  int jumpCounter;
  bool jump();
};
