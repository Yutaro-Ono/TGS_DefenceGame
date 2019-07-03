//-----------------------------------------------------------------------+
// エネミーマネージャークラス                              
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "EnemyManager.h"

const int EnemyManager::MAX_ENEMY_NUM = 5;           // 敵の一度に出現する最大数

void EnemyManager::Initialize()
{
	// エネミーモデルの読み込み
	m_enemySourceHandle = MV1LoadModel("Data/Model/Actor/Enemy/");


}

void EnemyManager::Delete()
{
}

void EnemyManager::Update()
{
}

void EnemyManager::Draw()
{
}
