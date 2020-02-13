#include "AnimationManager.h"
#include<Windows.h>

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

/// <summary>
/// アニメーションの切り替え
/// </summary>
/// <param name="nextState">次のキャラクターの状態</param>
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
      currentAnimation = new JumpAnimation(textures[static_cast<size_t>(state)].size());
      break;
  }
}

/// <summary>
/// ファイルからアニメーションを読み込む
/// </summary>
/// <param name="path">ファイルパス</param>
void AnimationManager<TextureRegion>::loadAnimation(const FilePath &path) {
  // 定数
  constexpr std::array<int, 4> eachAnimNum = {3, 4, 4, 7};
  constexpr Point textureSize(64, 64);

  Texture texture(path);

  if (!texture) {
    OutputDebugString((LPCWSTR)"Can't load chara texture");
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
