#pragma once
#include <Siv3D.hpp>

/**
 * @enum Enum
 * @brief �V�[���̏��
 */
enum class SceneState {
	Title,
	Game
};

using App = SceneManager<SceneState>;
