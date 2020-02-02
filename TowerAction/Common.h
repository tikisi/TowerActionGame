#pragma once
#include <Siv3D.hpp>

/**
 * @enum Enum
 * @brief シーンの状態
 */
enum class State {
	Title,
	Game
};

using App = SceneManager<State>;
