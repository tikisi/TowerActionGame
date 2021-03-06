#pragma once
#include <Siv3D.hpp>

/// <summary>
/// シーンの状態
/// </summary>
enum class SceneState {
	Title,
	Game
};

using App = SceneManager<SceneState>;
