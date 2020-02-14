#include "ActionManager.h"

#include <Windows.h>

/// <summary>
/// �A�j���[�V�����̐؂�ւ�
/// </summary>
/// <param name="nextState">���̃L�����N�^�[�̏��</param>
void ActionManager<TextureRegion>::changeAction(ActionState _nextState) {
  this->nextState = _nextState;
}

/// <summary>
/// �t�@�C������A�j���[�V������ǂݍ���
/// </summary>
/// <param name="path">�t�@�C���p�X</param>
void ActionManager<TextureRegion>::loadAnimation(const FilePath &path) {
  // �萔
  constexpr std::array<int, 4> eachAnimNum = {3, 4, 4, 7};
  constexpr Point textureSize(64, 64);

  Texture texture(path);

  if (!texture) {
    OutputDebugString((LPCWSTR) "Can't load chara texture");
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

template <class T>
void ActionManager<T>::update() {
  currentAction->update();
  this->accel += currentAction->getAccel();

  if (state != nextState) {
    delete currentAction;
    this->state = nextState;

    switch (state) {
      case ActionState::STAND:
        currentAction = new StandAction(
            this, textures[static_cast<size_t>(state)].size(), dir);
        break;
      case ActionState::Walk:
        currentAction = new WalkAction(
            this, textures[static_cast<size_t>(state)].size(), dir);
        break;
      case ActionState::JUMP:
        currentAction = new JumpAction(
            this, textures[static_cast<size_t>(state)].size(), dir);
        break;
    }

    // �V������Ԃ�update�Ăяo��
    currentAction->update();
    this->accel += currentAction->getAccel();
  }
}

template <class T>
T ActionManager<T>::getTexture() const {
  return textures[static_cast<size_t>(state)][currentAction->getIndex()];
}

template <class T>
Vec2 ActionManager<T>::getAccel() const {
  return this->currentAction->getAccel();
}

template <class T>
Direction ActionManager<T>::getDir() const {
  return this->dir = this->currentAction->getDir();
}

template <class T>
ActionState ActionManager<T>::getState() const {
  return this->state;
}

void ActionManager<TextureRegion>::update() {
  if (state != nextState) {
    this->dir = currentAction->getDir();
    delete currentAction;
    this->state = nextState;

    switch (state) {
      case ActionState::STAND:
        currentAction = new StandAction(
            this, textures[static_cast<size_t>(state)].size(), dir);
        break;
      case ActionState::Walk:
        currentAction = new WalkAction(
            this, textures[static_cast<size_t>(state)].size(), dir);
        break;
      case ActionState::JUMP:
        currentAction = new JumpAction(
            this, textures[static_cast<size_t>(state)].size(), dir);
        break;
    }
  }

  currentAction->update();
}

TextureRegion ActionManager<TextureRegion>::getTexture() const {
  return textures[static_cast<size_t>(state)][currentAction->getIndex()];
}

Vec2 ActionManager<TextureRegion>::getAccel() const {
  return this->currentAction->getAccel();
}

Direction ActionManager<TextureRegion>::getDir() const {
  return currentAction->getDir();
}

ActionState ActionManager<TextureRegion>::getState() const {
  return this->state;
}
