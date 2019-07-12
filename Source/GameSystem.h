//-----------------------------------------------------------+
// ゲームシステムクラス
//      : 全ての処理を行う
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Math.h"
#include "ModelLoader.h"
#include "Input.h"
#include "Camera.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include "PlayerManager.h"
#include "SceneBase.h"
#include "SceneTitle.h"
#include "SceneInGame.h"
#include "SceneResult.h"
#include <vector>

#pragma comment(lib, "winmm.lib")

class Input;
class Camera;
class SceneInGame;
class SceneResult;

class GameSystem
{
public:

	enum SCENE_PHASE
	{
		INIT = 0,
		START,
		TUTORIAL,
		GAME,
		GAME_END,
		SHUT_DOWN,
	};

	static GameSystem& GetInstance()
	{
		static GameSystem system;
		return system;
	}

	~GameSystem();            // デストラクタ

	bool Initialize();        // 各種初期化処理

	void Create();            // インスタンスなどの生成処理

	void Delete();            // 削除関数

	void RunLoop();           // ゲームループ

	void ShutDown();          // 終了処理

	// 画面設定のgetter
	const int& GetScreenWidth()const { return m_screenWidth; }
	const int& GetScreenHeight()const { return m_screenHeight; }
	// 画面設定のsetter
	void SetScreen(const int& scrWidth, const int& scrHeight, const bool& fullScreen);

private:
	GameSystem();                                // コンストラクタ   



	int Update();                                // Scene遷移更新用

	void UpdateMove();                           // 移動関連の更新

	void UpdateDraw();                           // 描画関連の更新

	bool ProgramLoop();                          // Windowsプロセスのエラーを返す


	SceneTitle* m_titleScene;                    // タイトルシーン
	SceneInGame* m_inGameScene;                  // インゲームシーン
	SceneResult* m_resultScene;                  // リザルトシーン

	Input* m_input;                              // 入力関連

	Camera* m_camera;                            // カメラ

	// ウィンドウ(Width : 幅, Height : 高さ)
	int m_screenWidth;
	int m_screenHeight;

	bool m_fullScreen;         // フルスクリーンかどうか
	bool m_isGameQuit;         // ゲームを終了するかどうか

	int sceneNum;              // どのシーンか

	float m_deltaTime;         // 1フレームの更新時間
};

 #define GAME_INSTANCE GameSystem::GetInstance()