//-----------------------------------------------------------------------+
// エネミークラス                            
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "Enemy.h"
// コンストラクタ
Enemy::Enemy(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
}

// デストラクタ
Enemy::~Enemy()
{
}

// 各種初期化処理
void Enemy::Initialize()
{

}

// 出現位置設定
void Enemy::SetEmergence(const VECTOR popPos)
{
	m_position = popPos;

	MV1SetPosition(m_modelHandle, m_position);
}

// ターゲットの方向に向く
void Enemy::GazeTarget()
{

}
