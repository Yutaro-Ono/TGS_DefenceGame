//-----------------------------------------------------------------------+
// ゲームシステムクラス                         
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include <iostream>
#include <Windows.h>
#include "EffekseerForDXLib.h"
#include "Camera.h"
#include "GameSystem.h"
#include "SceneTitle.h"
#include "SceneInGame.h"

// コンストラクタ
GameSystem::GameSystem()
	:m_screenWidth(0)
	,m_screenHeight(0)
	,m_fullScreen(false)
	,m_deltaTime(0.0f)
	,m_score(0)
{
	m_isGameQuit = false;
}

// デストラクタ
GameSystem::~GameSystem()
{
	// 処理なし
}

// 各種初期化
bool GameSystem::Initialize()
{
	// 画面を設定
	SetScreen(1920, 1080, true);
	// 全画面表示フラグがオフだったらウィンドウモードにする
	if (m_fullScreen)
	{
		ChangeWindowMode(TRUE);
	}
	// 画面設定を更新
	SetGraphMode(m_screenWidth, m_screenHeight, 32, 60);

	SetFontSize(50);                                          // 使用するフォントサイズを設定
	SetMouseDispFlag(TRUE);                                   // マウスカーソルの表示
	SetDrawScreen(DX_SCREEN_BACK);                            // 描画先を裏画面にセット

		// DXライブラリとEffekseerの初期化処理
	if (DxLib_Init() == -1 || Effekseer_Init(8000) == -1)
	{
		return false;			                              // エラーが起きたら直ちに終了
	}

	//---------------------------------------------------+
    // Effekseer関連の初期化
    //---------------------------------------------------+
	SetUseDirect3DVersion(DX_DIRECT3D_11);                    // DirectX11を使用
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	SetUseZBuffer3D(TRUE);                                    // ZBufferを使用
	SetWriteZBuffer3D(TRUE);                                  // ZBufferへの書き込みを許可

	return true;
}

// 生成処理
void GameSystem::Create()
{
	// カメラを生成
	m_camera = new Camera();
	// 入力システムを生成
	m_input = new Input();
	// フォントシステムを生成
	m_text = new TextGraph();
	m_text->Initialize();
	// シーンを生成(タイトル)
	m_scene = new SceneTitle();
	m_scene->Initialize();
}

// 解放処理
void GameSystem::Delete()
{
	m_scene->Delete();
}

// 更新処理
int GameSystem::Update()
{
	return 0;
}

// エラー監視
bool GameSystem::ProgramLoop()
{
	// Windowsの処理にエラーが起こった,またはEscキー,BACKボタンで終了
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

	// シーンの生成処理
	Create();

	while (ProgramLoop() || m_isGameQuit == true)
	{
		//時間計測
		nowTick = timeGetTime();
		DWORD m_Ticks = nowTick - prevTick;
		prevTick = timeGetTime();

		m_deltaTime = m_Ticks / 1000.0f;
		prevTick = nowTick;

		ClearDrawScreen();

		// Effekseer側のカメラとDxライブラリ側のカメラを同期する
		Effekseer_Sync3DSetting();

		// 登録パッドの更新
		m_input->ScanPadNum(PAD_NUM::PLAYER_1);

		//----------------------------------------------------+
		// ゲームシーンの更新処理
		//----------------------------------------------------+
		// シーンの更新処理
		m_scene->Update(*m_camera, *m_input, m_deltaTime);

		// 次のシーンをtmpに一時取得
		m_tmpScene = m_scene->SceneUpdate(*m_input);


		// シーンが変更されていなかった場合は描画を実行
		if (m_tmpScene == m_scene)
		{
			// 描画処理
			m_scene->Draw(*m_text);
			// Effekseerの更新
			UpdateEffekseer3D();
			// Effekseerの描画
			DrawEffekseer3D();

			ScreenFlip();
		}
		// シーンが変更されていた場合は描画をスキップしてシーン情報を更新
		else
		{
			ScreenFlip();
			// ロード中のテキスト表示
			m_text->DrawTextMessage(1450, 1030, "NOW LOADING...");
			ScreenFlip();

			// 解放処理
			m_scene->Delete();
			// 次のシーンを格納し初期化
			m_scene = m_tmpScene;
			m_scene->Initialize();
		}

		// BACKボタンでループを抜ける
		if (m_input->GetPushButtonState(XINPUT_BUTTON::XINPUT_BACK))
		{
			break;
		}
	}

	// 終了処理
	ShutDown();

	Effkseer_End();
	DxLib_End();

	// メモリリーク検出
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

// 終了処理
void GameSystem::ShutDown()
{
	Delete();
	m_text->Delete();

	delete (m_scene);
	delete (m_tmpScene);
	delete (m_camera);
	delete (m_input);
	delete (m_text);
}

// 画面情報(width : 横幅, Height : 縦幅, 全画面表示かどうか)のセッター
void GameSystem::SetScreen(const int & scrWidth, const int & scrHeight, const bool & fullScreen)
{
	m_screenWidth = scrWidth;
	m_screenHeight = scrHeight;
	m_fullScreen = fullScreen;
}