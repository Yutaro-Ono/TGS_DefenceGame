//-----------------------------------------------------------------------+
// ゲームシステムクラス                         
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include <iostream>
#include <Windows.h>
#include "Camera.h"
#include "GameSystem.h"
#include "SceneInGame.h"

// コンストラクタ
GameSystem::GameSystem()
	:m_screenWidth(0)
	,m_screenHeight(0)
	,m_fullScreen(false)
	,m_deltaTime(0.0f)
{
	m_isGameQuit = false;
}

// デストラクタ
GameSystem::~GameSystem()
{
	// 処理なし
}

bool GameSystem::Initialize()
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return false;			// エラーが起きたら直ちに終了
	}

	SetScreen(1600, 900, true);

	// 全画面表示フラグがオフだったらウィンドウモードにする
	if (m_fullScreen)
	{
		ChangeWindowMode(TRUE);
	}

	// 画面設定を更新
	SetGraphMode(m_screenWidth, m_screenHeight, 32, 60);

	SetMouseDispFlag(TRUE);      // マウスカーソルの表示

	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}


int GameSystem::Update()
{
	return 0;
}


// 移動関連の更新
void GameSystem::UpdateMove()
{
}

// 描画関連の更新
void GameSystem::UpdateDraw()
{
}


// エラー監視
bool GameSystem::ProgramLoop()
{
	// Windowsの処理にエラーが起こった,またはEscで終了
	if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE))
	{
		return false;
	}

	return true;
}

// ゲームループ
void GameSystem::RunLoop()
{
	// 現在時刻, 前回時刻を記録する
	DWORD nowTick, prevTick;
	prevTick = timeGetTime();

	m_scene = new SceneInGame();
	m_scene->Initialize();

	m_camera = new Camera();

	while (ProgramLoop())
	{
		//時間計測
		nowTick = timeGetTime();
		DWORD m_Ticks = nowTick - prevTick;
		prevTick = timeGetTime();

		m_deltaTime = m_Ticks / 1000.0f;
		prevTick = nowTick;

		// シーンの更新
		m_scene->Update(*m_camera);

		ClearDrawScreen();

		// 描画
		m_scene->Draw();

		ScreenFlip();

	}

}

// 終了処理
void GameSystem::ShutDown()
{
	m_scene->Delete();

	delete (m_camera);
	delete (m_scene);

	DxLib_End();
}

// 画面情報(width : 横幅, Height : 縦幅, 全画面表示かどうか)のセッター
void GameSystem::SetScreen(const int & scrWidth, const int & scrHeight, const bool & fullScreen)
{
	m_screenWidth = scrWidth;
	m_screenHeight = scrHeight;
	m_fullScreen = fullScreen;
}
