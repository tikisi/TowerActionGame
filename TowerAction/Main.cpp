#include <HamFramework.hpp>
#include <Siv3D.hpp>  // OpenSiv3D v0.4.2
#include <iostream>

#include "Common.h"
#include "Game.h"
#include "Title.h"

void Main() {
   
  Scene::SetBackground(Color(0, 0, 0));
  // Scene::Resize(800, 600);
  Scene::Resize(1280, 720);
  //Window::Resize(854, 480, WindowResizeOption::KeepSceneSize);
  Window::Resize(1280, 720, WindowResizeOption::KeepSceneSize);
 // Window::Resize(1920, 1080, WindowResizeOption::KeepSceneSize);
  //Window::Resize(640, 480, WindowResizeOption::KeepSceneSize);

  App manager;
  manager.add<Title>(SceneState::Title);
  manager.add<Game>(SceneState::Game);

  while (System::Update()) {
    if (!manager.update()) {
      break;
    }
  }
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
