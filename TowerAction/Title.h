#pragma once
#include "Common.h"

/**
 * @class Title
 * @brief タイトル画面
 */
class Title : public App::Scene
{
private:
  // タイトル画面の文字
	Font titleMessage;

public:

	Title(const InitData& init) : IScene(init) {
		this->titleMessage = Font(100);
	};

	void update() override;

	void draw() const override;
};
