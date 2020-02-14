#pragma once
#include <Siv3D.hpp>

class Physics {
 public:
  Point size;
  Vec2 pos;
  Vec2 speed;
  Vec2 accel;
  const Vec2 e; // Vec2(–€CŒW”A‹ó‹C’ïR)
  const Vec2 g; // d—Í

  Physics(Point size, Vec2 pos, Vec2 speed = Vec2(0, 0),
          Vec2 accel = Vec2(0, 0), Vec2 e = Vec2(0.2f, 0.08f),
          Vec2 g = Vec2(0, 0.25f))
      : size(size), pos(pos), speed(speed), accel(accel), e(e), g(g) {}

  void update();
};
