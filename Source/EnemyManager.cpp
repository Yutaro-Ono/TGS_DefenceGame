//-----------------------------------------------------------------------+
// エネミーマネージャークラス                              
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "EnemyManager.h"
#include "HitChecker.h"


const int EnemyManager::ENEMY_MAX_NUM = 5;           // 敵の一度に出現する最大数
const int EnemyManager::ENEMY_ALL_NUM = 25;          // 敵の合計数

// 各種初期化(モデルの読み込み、ポジション設定)
void EnemyManager::Initialize()
{
	// エネミーモデルの読み込み
	m_enemySourceHandle = MV1LoadModel("Data/Model/Actor/Enemy/Low_poly_ufo_FBX/Low_poly_UFO.mv1");

	// エネミーの生成(初期値)
	for (int i = 0; i < ALL_ENEMY; i++)
	{
		m_enemy.push_back(new Enemy(m_enemySourceHandle));
	}

	// 出現位置の設定(円形)
	for (int i = 0; i < m_enemy.size(); i++)
	{
		// cos((360.0f - (360.0f / enemy.size()) * i) * PI / 180.0f)
		//                                                   半径
		m_enemy[i]->SetEmergence(VGet(cos((360.0f - (360.0f / m_enemy.size()) * i) * PI / 180.0f) * 120.0f, 0, 40.0f + sin(((360.0f / m_enemy.size()) * i) * PI / 180.0f) * 120.0f));
	}
}

// 各種解放処理
void EnemyManager::Delete()
{
	// モデルを削除
	MV1DeleteModel(m_enemySourceHandle);
	
	for (int i = 0; i < m_enemy.size(); i++)
	{
		delete (m_enemy[i]);
		m_enemy[i] = NULL;
	}

}

// 更新処理
void EnemyManager::Update(PlayerManager& playerManager, float deltaTime)
{

	for (int i = 0; i < m_enemy.size(); i++)
	{
		// プレイヤーとのヒットフラグが立っていない時のみ更新
		if (m_enemy[i]->GetHitPlayer() == false)
		{
			m_enemy[i]->Update(deltaTime);
			m_enemy[i]->GazeTarget(playerManager, deltaTime);
		}

		m_enemy[i]->HitInterval();
	}
}

// 描画処理
void EnemyManager::Draw()
{
	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->Draw();
	}
}

// エネミーの追加処理
void EnemyManager::AddEnemy()
{
	 m_enemy.emplace_back(new Enemy(m_enemySourceHandle));
	//// エネミーの座標を設定
	//m_enemy[m_enemy.size()]->SetEmergence(VGet(0.0f, 0.0f, 0.0f));
}
