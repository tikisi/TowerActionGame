#pragma once
#include <Siv3D.hpp>

/**
 * @enum Enum
 * @brief �V�[���̏��
 */
enum class State {
	Title,
	Game
};

using App = SceneManager<State>;
