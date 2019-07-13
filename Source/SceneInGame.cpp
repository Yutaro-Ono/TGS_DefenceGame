//----------------------------------------------------------------------+
// inゲーム(ゲーム中)シーン                               
//                                              Last Update : 2019/07/12
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "Timer.h"
#include "PlayerManager.h"
#include "Camera.h"
#include "HitChecker.h"

class Timer;

// コンストラクタ
SceneInGame::SceneInGame()
{
	m_player = NULL;
	m_enemy = NULL;
	toNext = 3;
}

// デストラクタ
SceneInGame::~SceneInGame()
{
}

// 各種初期化処理
void SceneInGame::Initialize()
{
	// プレイヤーを生成，初期化
	m_player = new PlayerManager();
	m_player->Initialize();
	// エネミーを生成，初期化
	m_enemy = new EnemyManager();
	m_enemy->Initialize();
	// UIを生成、初期化
	m_UI = new InGameUIManager();
	m_UI->Initialize();
	// オブジェクトを生成，初期化
	m_obj = new ObjectManager();
	m_obj->Initialize();

	TIMER_INSTANCE.Initialize();
	m_popCount = 0;
}

// 各種解放処理
void SceneInGame::Delete()
{
	delete (m_player);
	delete (m_enemy);
	delete (m_obj);
	delete (m_UI);
}

// オーバーライドしたアップデート(処理なし)
void SceneInGame::Update(Input & input, Camera & camera, float deltaTime)
{
}

// 更新処理
void SceneInGame::Update(Input& input, Camera& camera, SceneResult& result, float deltaTime)
{

	// キーの押下状態チェック
	input.KeyChecker();

	// カメラの更新
	camera.Update(*m_player);

	// 当たり判定処理
	HitChecker::CheckHit(*m_player, *m_enemy);

	for (int i = 0; i < m_enemy->GetActiveEnemy(); i++)
	{
		HitChecker::CheckHitEnemy(*m_enemy, i);
	}

	// プレイヤーの更新
	m_player->Update(input, deltaTime);
	// エネミーの更新
	m_enemy->Update(*m_player, deltaTime);

	// 残り時間によってエネミーを追加
	if (TIMER_INSTANCE.GetTimer() == 50 && m_popCount == 0)
	{
		m_enemy->AddEnemy();
		m_popCount = 1;
	}
	if (TIMER_INSTANCE.GetTimer() == 45 && m_popCount == 1)
	{
		m_enemy->AddEnemy();
		m_popCount = 2;
	}
	if (TIMER_INSTANCE.GetTimer() == 40 && m_popCount == 2)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 3;
	}
	if (TIMER_INSTANCE.GetTimer() == 35 && m_popCount == 3)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 4;
	}
	if (TIMER_INSTANCE.GetTimer() == 30 && m_popCount == 4)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 5;
	}
	if (TIMER_INSTANCE.GetTimer() == 25 && m_popCount == 5)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 6;
	}
	if (TIMER_INSTANCE.GetTimer() == 20 && m_popCount == 6)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 7;
	}
	
	if (TIMER_INSTANCE.GetPrevTimer() - TIMER_INSTANCE.GetTimer() >= 1 )
	{
		
	}

	TIMER_INSTANCE.Update();

	// 描画関数総合
	Draw();

	// シーンアップデート
	SceneUpdate(result);
}

// シーンのアップデート(主に次シーンへの遷移処理)
void SceneInGame::SceneUpdate(SceneResult & result)
{
	// タイマーが0になったら、ゲームクリアとして次のシーンへ
	if (TIMER_INSTANCE.GetTimer() <= 0)
	{
		result.SetClear(true);
		toNext = 4;
	}

	// プレイヤーが死亡状態だったら、ゲームオーバーとして次のシーンへ
	if (m_player->GetPlayerState() == m_player->PLAYER_STATE::DEAD)
	{
		result.SetClear(false);
		toNext = 4;
	}
}

// 描画処理
void SceneInGame::Draw()
{
	// オブジェクトの描画
	m_obj->Draw();
	// エネミーの描画
	m_enemy->Draw();
	// プレイヤーの描画
	m_player->Draw();
	// UIの描画
	m_UI->Draw(*m_player->GetPlayerPointer());
	// タイマーの描画
	TIMER_INSTANCE.Draw();
}
