#include "Game.h"

void Game::update() {
  this->player.upate();
  for (const auto block : this->blocks) {
   this->player.collisionWithBlock(*block);
  }
}

void Game::draw() const {
  for(const auto block : this->blocks) {
    block->draw();
  }
  this->player.draw();
}
