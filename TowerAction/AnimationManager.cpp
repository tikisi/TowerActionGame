#include "AnimationManager.h"

template <class T>
void AnimationManager<T>::update() {
  currentAnimation->update();
}

template <class T>
T AnimationManager<T>::getTexture() const{
  return textures[static_cast<size_t>(state)][currentAnimation->getIndex()];
}

void AnimationManager<TextureRegion>::update() {
  currentAnimation->update();
}

TextureRegion AnimationManager<TextureRegion>::getTexture() const {
  return textures[static_cast<size_t>(state)][currentAnimation->getIndex()];
}

void AnimationManager<TextureRegion>::changeAnimation(PlayerState nextState) {
  delete currentAnimation;
  this->state = nextState;
  
  switch (state) {
    case PlayerState::STAND:
      currentAnimation = new StandAnimation(textures[static_cast<size_t>(state)].size());
      break;
    case PlayerState::Walk:
      currentAnimation = new WalkAnimation(textures[static_cast<size_t>(state)].size());
      break;
    case PlayerState::JUMP:
      currentAnimation = new WalkAnimation(textures[static_cast<size_t>(state)].size());
      break;
  }
}

void AnimationManager<TextureRegion>::loadAnimation(FilePath path) {
  Texture texture(path);
  Point textureSize = Point(64, 64);
  int eachAnimNum[4] = {3, 4, 4, 7};

  if (!texture) {
    std::cerr << "Can't load texture :" << path << std::endl;
    exit(1);
  }

  // create divTexture
  for (auto i : step(4)) {
    Array<TextureRegion> each;
    for (auto j : step(eachAnimNum[i])) {
      each.push_back(
          texture(j * textureSize.x, i * textureSize.y, textureSize));
    }
    textures.push_back(each);
  }
}
