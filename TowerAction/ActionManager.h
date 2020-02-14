#pragma once
#include <Siv3D.hpp>
#include "Action.h"
#include "Physics.h"

/// <summary>
/// アニメーション管理クラス
/// </summary>
template <class T>
class ActionManager : public ActionChanger {
 protected:
  Array<Array<T>> textures;
  ActionState state;
  ActionState nextState;
  Action *currentAction;
  Direction dir;
  Vec2 accel;

 public:
  ActionManager() = default;
  void changeAction(ActionState nextState) override {};
  void loadAnimation(const FilePath &path){};
  void update();

  T getTexture() const;
  Vec2 getAccel() const;
  Direction getDir() const;
  ActionState getState() const;
};


/// <summary>
/// アニメーション管理クラスのTextureRegionへの特殊化
/// </summary>
template <>
class ActionManager<TextureRegion> : public ActionChanger {
 protected:
  Array<Array<TextureRegion>> textures;
  ActionState state;
  ActionState nextState;
  Action *currentAction;
  Direction dir;

 public:
  ActionManager(FilePath path) {
    this->loadAnimation(path);
    currentAction = new StandAction(this,
        textures[static_cast<size_t>(ActionState::STAND)].size(), Direction::Right);
    this->state = ActionState::STAND;
    this->nextState = this->state;
    this->dir = Direction::Right;
  }

  void changeAction(ActionState nextState) override;
  void loadAnimation(const FilePath &path);
  void update();

  TextureRegion getTexture() const;
  Vec2 getAccel() const;
  Direction getDir() const;
  ActionState getState() const;
};
