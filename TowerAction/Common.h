#pragma once
#include <Siv3D.hpp>

/**
 * @enum Enum
 * @brief ƒV[ƒ“‚Ìó‘Ô
 */
enum class State {
	Title,
	Game
};

using App = SceneManager<State>;
