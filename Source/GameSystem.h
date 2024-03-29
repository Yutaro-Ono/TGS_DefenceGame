//-----------------------------------------------------------+
// ゲームシステムクラス
//      : 全ての処理を行う
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once
#pragma comment(lib, "winmm.lib")

// インクルードファイル
#include "DxLib.h"
#include "Math.h"
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
#include "TextGraph.h"

// クラス前方宣言
class Input;
class Camera;
class SceneInGame;
class SceneResult;

class GameSystem
{

public:

	// シングルトン
	static GameSystem& GetInstance()
	{
		static GameSystem system;
		return system;
	}
	
	~GameSystem();                               // デストラクタ

	bool Initialize();                           // 各種初期化処理

	void Create();                               // インスタンスなどの生成処理

	void Delete();                               // 削除関数

	void RunLoop();                              // ゲームループ

	void ShutDown();                             // 終了処理

	//--------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------+
	// 画面設定(縦横)のゲッター
	const int& GetScreenWidth()const { return m_screenWidth; }
	const int& GetScreenHeight()const { return m_screenHeight; }
	// 画面設定のセッター
	void SetScreen(const int& scrWidth, const int& scrHeight, const bool& fullScreen);
	// ゲーム終了のセッター
	void SetGameQuit(bool in_quit) { m_isGameQuit = true; }


private:

	GameSystem();                                // コンストラクタ

	int Update();                                // Scene遷移更新用
	bool ProgramLoop();                          // Windowsプロセスのエラーを返す

	SceneBase* m_scene;                          // シーン
	SceneBase* m_tmpScene;                       // シーン情報の一時保存用
	Camera* m_camera;                            // カメラ
	Input* m_input;                              // 入力
	TextGraph* m_text;                           // 描画用フォント

	// ウィンドウ(Width : 幅, Height : 高さ)
	int m_screenWidth;
	int m_screenHeight;

	bool m_fullScreen;                           // フルスクリーンかどうか
	bool m_isGameQuit;                           // ゲームを終了するかどうか

	float m_deltaTime;                           // 1フレームの更新時間

	int m_score;                                 // スコア保存用

};

 #define GAME_INSTANCE GameSystem::GetInstance()