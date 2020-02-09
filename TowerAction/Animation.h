#pragma once
#include <Siv3D.hpp>


class Animation {
 protected:
  const size_t size;
  size_t index;
  int frameCounter;

 public:
  Animation(size_t size) : size(size) { this->initialize();}
  void initialize();

  size_t getIndex() const; 

  virtual void update() = 0;
};


class StandAnimation : public Animation {
 private:
 public:
  StandAnimation(size_t size) : Animation(size){};

  void update() override;
};


class WalkAnimation : public Animation {
 private:
 public:
  WalkAnimation(size_t size) : Animation(size){};

  void update() override;
};
