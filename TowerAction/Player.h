#pragma once
#include <Siv3D.hpp>

#include "AnimationManager.h"

/**
 * @class Player
 * �v���C���[�N���X
 */
class Player {
  enum class Direction { Right, Left };

 private:
  Point textureSize;
  AnimationManager<TextureRegion> animationManager;

  //------�L�����̏��---------
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

    this->speed0 = -6.0f;
    this->gravity = 0.2;
    this->speed = speed0;
  }

  void upate();

  void draw() const;

  // jump�p�ϐ�
 private:
  float speed;
  float gravity;
  float speed0;
  int jumpCounter;
  bool jump();
};
