#pragma once
#include <Siv3D.hpp>
#include "Animation.h"

/// <summary>
/// キャラクターの状態 
/// </summary>
enum class PlayerState : size_t { STAND = 0, Walk, Dash, JUMP };

/// <summary>
/// アニメーション管理クラス
/// </summary>
template <class T>
class AnimationManager {
 protected:
  Array<Array<T>> textures;
  PlayerState state;
  Animation *currentAnimation;

 public:
  AnimationManager() = default;
  void changeAnimation(PlayerState nextState){};
  void loadAnimation(const FilePath &path){};
  void update();
  T getTexture() const;
};


/// <summary>
/// アニメーション管理クラスのTextureRegionへの特殊化
/// </summary>
template <>
class AnimationManager<TextureRegion> {
 protected:
  Array<Array<TextureRegion>> textures;
  PlayerState state;
  Animation *currentAnimation;

 public:
  AnimationManager(FilePath path) {
    this->loadAnimation(path);
    currentAnimation = new StandAnimation(
        textures[static_cast<size_t>(PlayerState::STAND)].size());
    this->state = PlayerState::STAND;
  }

  void changeAnimation(PlayerState nextState);
  void loadAnimation(const FilePath &path);
  void update();
  TextureRegion getTexture() const;
};
