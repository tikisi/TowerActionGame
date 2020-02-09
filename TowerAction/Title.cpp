#include "Title.h"

void Title::update() {
  if (SimpleGUI::ButtonAt(U"Start", Scene::Center().moveBy(Point(0, 100)))) {
    changeScene(SceneState::Game);
  }
}

void Title::draw() const {
  this->titleMessage(U"Title").drawAt(Scene::Center());
}