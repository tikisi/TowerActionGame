#include "Physics.h"

void Physics::update() {
  this->accel += this->g;
  this->speed += this->accel - (this->speed * this->e);
  this->pos += this->speed;
}
