#pragma once
#include <Siv3D.hpp>

/**
 * @enum Enum
 * @brief ƒV[ƒ“‚Ìó‘Ô
 */
enum class SceneState {
	Title,
	Game
};

using App = SceneManager<SceneState>;
