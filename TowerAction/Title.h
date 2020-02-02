#pragma once
#include "Common.h"

/**
 * @class Title
 * @brief �^�C�g�����
 */
class Title : public App::Scene
{
private:
  // �^�C�g����ʂ̕���
	Font titleMessage;

public:

	Title(const InitData& init) : IScene(init) {
		this->titleMessage = Font(100);
	};

	void update() override;

	void draw() const override;
};
