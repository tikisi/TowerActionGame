#include "Physics.h"

void Physics::update() {
  this->accel += this->g;
  this->speed += this->accel - (this->speed * this->e);
  this->pos += this->speed.asPoint();
}

Physics::Edge Physics::collision(const BaseBlock& block) {
  // ���S���W
  Float2 centerA = Float2(pos.x + (size.x / 2.0f), pos.y + (size.y / 2.0f));
  Float2 centerB = centerA - speed;

  // �u���b�N�̊e���_
  Float2 a = block.pos;
  Float2 b(a.x + block.size.x, a.y);
  Float2 c = a + block.size;
  Float2 d(a.x, a.y + block.size.y);

  float dx = abs(centerA.x - (block.pos.x + block.size.x / 2.0f));
  float dy = abs(centerA.y - (block.pos.y + block.size.y / 2.0f));

  if ((block.size.x + size.x) / 2.0f > dx &&
      (block.size.y + size.y) / 2.0f > dy) {
    Print(U"collision");

    // 8��������
    // �k��
    if (speed.x > 0.01f && speed.y < -0.01f) {
      if ((b - d).cross(centerB - d) < 0) {
        speed.x = 0.0f;
        pos.x = a.x - size.x;
        return Edge::bc;
      } else {
        speed.y = 0.0f;
        pos.y = d.y;
        return Edge::ab;
      }
    } else if (speed.x < -0.01f && speed.y > 0.01f) {
      // �쐼
      if ((b - d).cross(centerB - d) < 0) {
        speed.y = 0.0f;
        pos.y = a.y -
          size.y;
        return Edge::cd;
      } else {
        speed.x = 0.0f;
        pos.x = b.x;
        return Edge::da;
      }
    } else if (speed.x < -0.01f && speed.y < -0.01f) {
      // �k��
      if ((a - c).cross(centerB - c) < 0) {
        speed.y = 0;
        pos.y = c.y;
        return Edge::ab;
      } else {
        speed.x = 0;
        pos.x = b.x;
        return Edge::da;
      }
    } else if (speed.x > 0.01f && speed.y > 0.01f) {
      //�쓌
      if ((a - c).cross(centerB - c) < 0) {
        speed.x = 0;
        pos.x = a.x - size.x;
        return Edge::bc;
      } else {
        speed.y = 0;
        pos.y = a.y - size.y;
        return Edge::cd;
      }
    } else if (speed.x > 0.01f && abs(speed.y) <= 0.01f) {
      // ��
      speed.x = 0.0f;
      pos.x = block.pos.x - size.x;
      return Edge::bc;
    } else if (speed.x < -0.01f && abs(speed.y) <= 0.01f) {
      // ��
      speed.x = 0.0f;
      pos.x = block.pos.x + block.size.x;
      return Edge::da;
    } else if (abs(speed.x) <= 0.01f && speed.y > 0.01f) {
      // ��
      speed.y = 0.0f;
      pos.y = block.pos.y - size.y;
      return Edge::cd;
    } else if (abs(speed.x) <= 0.01f && speed.y < -0.01f) {
      // ��
      speed.y = 0.0f;
      pos.y = block.pos.y + block.size.y;
      return Edge::ab;
    }
  }

  return Edge::none;
}
