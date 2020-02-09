#include "Game.h"

void Game::update() {
  this->player.upate();
}

void Game::draw() const {
  this->player.draw();
}
