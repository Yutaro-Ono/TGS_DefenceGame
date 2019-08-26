//----------------------------------------------------------------------+
// inゲーム(ゲーム中)のシーンクラス
//      : ゲーム中の総合的な処理をここで行う (シーン基底クラスを継承)
//                                             Last Update : 2019/07/13
//----------------------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "SceneBase.h"
#include "SceneResult.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include "ObjectManager.h"
#include "InGameUIManager.h"
#include "DirectorCountDown.h"
#include "Camera.h"
#include "Timer.h"
#include "SoundFX.h"


class SceneBase;
class SceneResult;
class PlayerManager;
class EnemyManager;
class ItemManager;
class InGameUIManager;
class ObjectManager;
class Player;
class CountDown;
class Camera;
class Timer;
class SoundFX;


class SceneInGame : public SceneBase
{
public:

	SceneInGame();                                // コンストラクタ
	~SceneInGame();                               // デストラクタ

	// ゲームシーン中のフェーズ
	enum GAME_PHASE
	{
		START_COUNTDOWN,
		IN_GAME,
		INTERVAL,
	};

	void Initialize() override;                   // 各種初期化処理

	void Delete() override;                       // 各種解放処理

	void PlaceEnemyByTime();                      // 時間ごとにエネミーを追加配置する関数

	void Draw()override;                          // 描画処理

	// 更新処理
	void Update(Camera& camera, Input& input, float deltaTime)override;

	//--------------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------------+

	SceneBase* SceneUpdate(Input& input) override;

private:

	int toNext;                                    // 次シーンへのハンドル

	bool m_startGame;                              // このフラグが立ったらゲームを開始する

	bool m_setTimer;                               // ゲームシーン起動時、タイマーのセットフラグ

	int m_popCount;                                // エネミーの出現カウンター

	bool m_isGameOver;                             // ゲームオーバーになったかどうか   
	
	bool m_isClear;                                  // ゲームをクリアしたかどうか

	Timer* m_timer;                                  // タイマー
	PlayerManager* m_player;                       // プレイヤー
	EnemyManager* m_enemy;                         // エネミー
	ItemManager* m_item;                           // アイテム
	InGameUIManager* m_UI;                         // UI
	ObjectManager* m_obj;                          // オブジェクト
	SoundFX* m_bgm;                                // BGM


	CountDown* m_countdown;                     // カウントダウン演出

	static const int MAX_GAME_TIME;     // ゲーム制限時間
};