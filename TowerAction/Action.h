#pragma once
#include <Siv3D.hpp>

// キャラクタの向き
enum class Direction : int { Right, Left };

/// <summary>
/// キャラクターの状態
/// </summary>
enum class ActionState : size_t { STAND = 0, Walk, Dash, JUMP };

class ActionSetter {
 public:
  virtual void setNextAction(ActionState _nextState) = 0;
};

/// <summary>
/// アニメーションの基底クラス
/// </summary>
class Action {
 protected:
  ActionSetter *changer;
  const size_t size;
  Direction dir;
  size_t index;
  Vec2 accelVariation;
  int frameCounter;

 public:
  Action(ActionSetter *changer, size_t size, Direction dir) : size(size), changer(changer), dir(dir) {
    this->initialize();
  }
  void initialize();

  size_t getIndex() const;
  Vec2 getAccel() const;
  Direction getDir() const;

  virtual void update() = 0;
};

class StandAction : public Action {
 private:
 public:
  StandAction(ActionSetter *changer, size_t size, Direction dir) : Action(changer, size, dir) {
    this->accelVariation = Vec2(0, 0);
  }

  void update() override;
};

class WalkAction : public Action {
 private:
 public:
  WalkAction(ActionSetter *changer, size_t size, Direction dir);

  void update() override;
};

class JumpAction : public Action {
 private:
 public:
  JumpAction(ActionSetter *changer, size_t size, Direction dir) : Action(changer, size, dir) {};

  void update() override;
};
