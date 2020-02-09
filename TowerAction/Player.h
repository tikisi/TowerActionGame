#pragma once
#include <Siv3D.hpp>

#include "AnimationManager.h"

/**
 * @class Player
 * プレイヤークラス
 */
class Player {
 public:
 private:
  Point textureSize;
  AnimationManager<TextureRegion> animationManager;

  //------キャラの情報---------
  Point position;
  PlayerState state;

 public:
  Player() = default;
  ~Player() = default;

  Player(Point position, Point textureSize = Point(64, 64),
         FilePath path = U"../Asset/UnityChan.png")
      : position(position), animationManager(path), textureSize(textureSize) {
    this->state = PlayerState::STAND;
  }

  void upate();

  void draw() const;
};
