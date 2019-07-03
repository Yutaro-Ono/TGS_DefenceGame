//-----------------------------------------------------------------------+
// エネミーマネージャークラス                              
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "EnemyManager.h"

const int EnemyManager::MAX_ENEMY_NUM = 5;           // 敵の一度に出現する最大数

// 各種初期化(モデルの読み込み、ポジション設定)
void EnemyManager::Initialize()
{
	// エネミーモデルの読み込み
	m_enemySourceHandle = MV1LoadModel("Data/Model/Actor/Enemy/");
}

// 各種解放処理
void EnemyManager::Delete()
{
	// モデルを削除
	MV1DeleteModel(m_enemySourceHandle);


}

// 更新処理
void EnemyManager::Update()
{

}

// 描画処理
void EnemyManager::Draw()
{

}
