#pragma once
#include <Siv3D.hpp>

class BaseBlock {
 public:
  Float2 size;
  Float2 pos;

  BaseBlock(Float2 pos, Float2 size = Float2(30, 30)) : size(size), pos(pos) {}
  BaseBlock(int posX, int posY, int width = 32, int height = 32)
      : pos(Float2(posX, posY)), size(Float2(width, height)) {}

  void draw() const { Rect(pos.asPoint(), size.asPoint()).drawFrame(1, 1, Palette::Green); }
};
