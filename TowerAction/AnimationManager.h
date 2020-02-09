#pragma once
#include <Siv3D.hpp>
#include "Animation.h"

enum class PlayerState : size_t { STAND = 0, Walk, Dash, JUMP };

// ëΩólëÃÅ@+ change()
template <class T>
class AnimationManager {
 protected:
  Array<Array<T>> textures;
  PlayerState state;
  Animation *currentAnimation;

 public:
  AnimationManager() = default;
  void changeAnimation(PlayerState nextState){};
  void loadAnimation(FilePath path){};
  void update();
  T getTexture() const;
};

template <>
class AnimationManager<TextureRegion> {
 protected:
  Array<Array<TextureRegion>> textures;
  PlayerState state;
  Animation *currentAnimation;

 public:
  AnimationManager(FilePath path) {
    this->loadAnimation(path);
    currentAnimation = new StandAnimation(textures[static_cast<size_t>(PlayerState::STAND)].size());
    this->state = PlayerState::STAND;
  }

  void changeAnimation(PlayerState nextState);
  void loadAnimation(FilePath path);
  void update();
  TextureRegion getTexture() const;
};
