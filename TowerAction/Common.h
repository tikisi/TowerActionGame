#pragma once
#include <Siv3D.hpp>

/// <summary>
/// �V�[���̏��
/// </summary>
enum class SceneState {
	Title,
	Game
};

using App = SceneManager<SceneState>;
