#pragma once
#include <Siv3D.hpp>

/// <summary>
/// ƒV[ƒ“‚Ìó‘Ô
/// </summary>
enum class SceneState {
	Title,
	Game
};

using App = SceneManager<SceneState>;
