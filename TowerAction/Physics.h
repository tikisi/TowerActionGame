#pragma once
#include <Siv3D.hpp>

class Physics {
 public:
  Point size;
  Vec2 pos;
  Vec2 speed;
  Vec2 accel;

  Physics(Point size, Vec2 pos, Vec2 speed = Vec2(0, 0),
          Vec2 accel = Vec2(0, 0))
      : size(size), pos(pos), speed(speed), accel(accel) {}

  void update() {
    speed += accel;
    pos += speed;
    ClearPrint();
    Print << speed;
  }
};
