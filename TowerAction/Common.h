#pragma once
#include <Siv3D.hpp>

/**
 * @enum Enum
 * @brief シーンの状態
 */
enum class SceneState {
	Title,
	Game
};

using App = SceneManager<SceneState>;
