#pragma once
#include <Siv3D.hpp>

#include "Block.h"

class Physics {
 public:
  // �Փ˂����ӂ�\��
  enum class Edge { ab, bc, cd, da, none};
  Float2 size;
  Float2 pos;
  Float2 speed;
  Float2 accel;
  const Float2 e;  // Vec2(���C�W���A��C��R)
  const Float2 g;  // �d��

  Physics(Float2 size, Float2 pos, Float2 speed = Float2(0, 0),
          Float2 accel = Float2(0, 0), Float2 e = Float2(0.2f, 0.05f),
          Float2 g = Float2(0, 0.25f))
      : size(size), pos(pos), speed(speed), accel(accel), e(e), g(g) {}

  void update();

  Physics::Edge collision(const BaseBlock &block);
};
