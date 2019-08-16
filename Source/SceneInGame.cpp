//----------------------------------------------------------------------+
// inゲーム(ゲーム中)シーン                               
//                                              Last Update : 2019/07/13
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "HitChecker.h"

const int SceneInGame::MAX_GAME_TIME = 60;

// コンストラクタ
SceneInGame::SceneInGame()
{
	m_player = NULL;
	m_enemy = NULL;
	m_item = NULL;
	toNext = 3;
}

// デストラクタ
SceneInGame::~SceneInGame()
{
}

// 各種初期化処理
void SceneInGame::Initialize()
{
	// タイマーを生成、初期化
	m_timer = new Timer();
	m_timer->Initialize();
	// プレイヤーを生成，初期化
	m_player = new PlayerManager();
	m_player->Initialize();
	// エネミーを生成，初期化
	m_enemy = new EnemyManager();
	m_enemy->Initialize();
	// アイテムを生成
	m_item = new ItemManager();
	m_item->Initialize();
	// UIを生成、初期化
	m_UI = new InGameUIManager();
	m_UI->Initialize();
	// オブジェクトを生成，初期化
	m_obj = new ObjectManager();
	m_obj->Initialize();
	// カウントダウン演出の生成、初期化
	m_countdown = new CountDown();
	m_countdown->Initialize();

	m_setTimer = false;
	m_popCount = 0;
}

// 各種解放処理
void SceneInGame::Delete()
{
	m_item->Delete();
	m_UI->Delete();

	delete (m_timer);
	delete (m_player);
	delete (m_enemy);
	delete (m_item);
	delete (m_obj);
	delete (m_UI);
	delete (m_countdown);
}

// オーバーライドしたアップデート(処理なし)
void SceneInGame::Update(Camera & camera, Input& input, float deltaTime)
{
}

// 更新処理
void SceneInGame::Update(Camera& camera, Input& input, SceneResult& result, float deltaTime)
{
	// カウントダウン処理(本来はカウントダウン専用の状況を作らなければならない)
	m_countdown->StartCountDown();

	//------------------------------------------------------+
	// タイマーの初期化
	//------------------------------------------------------+
	if (m_setTimer == false)
	{
		m_timer->Initialize();
		m_setTimer = true;
	}

	// カメラの更新
	camera.Update(*m_player);

	//------------------------------------------------------+
	// 当たり判定処理
	//------------------------------------------------------+
	// プレイヤーとエネミー
	HitChecker::CheckHit(*m_player, *m_enemy);
	// エネミー同士
	for (int i = 0; i < m_enemy->GetActiveEnemy(); i++)
	{
		HitChecker::CheckHitEnemy(*m_enemy, i);
	}
	// プレイヤーとアイテム
	HitChecker::CheckHitItem(*m_player, *m_item);
	// プレイヤーと回収ポッド
	HitChecker::CheckHitPod(*m_player, *m_obj);

	//------------------------------------------------------+
	// プレイヤーの更新
	//------------------------------------------------------+
	m_player->Update(input, deltaTime);
	// エネミーの更新
	m_enemy->Update(*m_player, deltaTime);
	// アイテムの更新
	m_item->Update(deltaTime);
	// UIの更新
	m_UI->Update(*m_player->GetPlayerPointer());
	// オブジェクトの更新
	m_obj->Update();

	// 残り時間によってエネミーとアイテムを追加
	if (m_timer->GetTimer() == 50 && m_popCount == 0)
	{
		m_enemy->AddEnemy();
		m_popCount = 1;
	}
	if (m_timer->GetTimer() == 45 && m_popCount == 1)
	{
		m_enemy->AddEnemy();
		m_popCount = 2;
	}
	if (m_timer->GetTimer() == 40 && m_popCount == 2)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 3;
	}
	if (m_timer->GetTimer() == 35 && m_popCount == 3)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 4;
	}
	if (m_timer->GetTimer() == 30 && m_popCount == 4)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 5;
	}
	if (m_timer->GetTimer() == 25 && m_popCount == 5)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 6;
	}
	if (m_timer->GetTimer() == 20 && m_popCount == 6)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();

		m_popCount = 7;
	}

	if (m_timer->GetTimer() % 10 == 0)
	{
		m_item->AddItem();
	}

	// タイマーの更新
	m_timer->UpdateCountDown(MAX_GAME_TIME);

	// 描画関数総合
	Draw();

	// シーンアップデート
	SceneUpdate(result);
}

// シーンのアップデート(リザルトシーンへの遷移処理)
void SceneInGame::SceneUpdate(SceneResult & result)
{
	// タイマーが0になったら、ゲームクリアとして次のシーンへ
	if (m_timer->GetTimer() <= 0)
	{
		result.SetClear(true);      // ゲームを無事クリアした
		toNext = 4;                 // リザルトへ
	}

	// プレイヤーが死亡状態だったら、ゲームオーバーとして次のシーンへ
	if (m_player->GetPlayerState() == m_player->PLAYER_STATE::DEAD)
	{
		result.SetClear(false);      // ゲームオーバーとなった
		toNext = 4;                  // リザルトへ
	}
}

void SceneInGame::PlaceEnemyByTime()
{
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
	m_timer->Draw();
}
