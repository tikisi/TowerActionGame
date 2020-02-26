#pragma once
#include <Siv3D.hpp>
#include "Action.h"
#include "Physics.h"

/// <summary>
/// アニメーション管理クラス
/// </summary>
template <class T>
class ActionManager : public ActionSetter {
 protected:
  Array<Array<T>> textures;
  ActionState state;
  ActionState nextState;
  Action *currentAction;

 public:
  ActionManager() = default;
  void setNextAction(ActionState nextState) override {};
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
class ActionManager<TextureRegion> : public ActionSetter {
 protected:
  Array<Array<TextureRegion>> textures;
  ActionState state;
  ActionState nextState;
  Action *currentAction;

 public:
  ActionManager(FilePath path) {
    this->loadAnimation(path);
    currentAction = new StandAction(this,
        textures[static_cast<size_t>(ActionState::STAND)].size(), Direction::Right);
    this->state = ActionState::STAND;
    this->nextState = this->state;
  }

  void setNextAction(ActionState nextState) override;
  void changeAction(ActionState nextState);
  void loadAnimation(const FilePath &path);
  void update();

  TextureRegion getTexture() const;
  Vec2 getAccel() const;
  Direction getDir() const;
  ActionState getState() const;
};
