//----------------------------------------------------------------------+
// inゲーム(ゲーム中)シーン                               
//                                              Last Update : 2019/07/01
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "PlayerManager.h"
#include "Camera.h"
#include "HitChecker.h"

// コンストラクタ
SceneInGame::SceneInGame()
{
	m_player = NULL;
	m_enemy = NULL;
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
	// オブジェクトを生成，初期化
	m_obj = new ObjectManager();
	m_obj->Initialize();
	// NPCを生成，初期化
	m_npc = new NpcManager();
	m_npc->Initialize();
}

// 各種解放処理
void SceneInGame::Delete()
{
	delete (m_player);
	delete (m_enemy);
	delete (m_obj);
	delete (m_npc);
}

// 更新処理
void SceneInGame::Update(Input& input, Camera& camera, float deltaTime)
{
	// キーの押下状態チェック
	input.KeyChecker();

	// カメラの更新
	camera.Update(*m_player);

	// プレイヤーの更新
	m_player->Update(input, deltaTime);
	// エネミーの更新
	m_enemy->Update(*m_player, deltaTime);
	// NPCの更新
	m_npc->Update(deltaTime);

	// 当たり判定処理
	HitChecker::CheckHit(*m_player, *m_enemy);
	for (int i = 0; i < ALL_ENEMY; i++)
	{
		HitChecker::CheckHitEnemy(*m_enemy, i);
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
	// NPCの描画
	//m_npc->Draw();
}
