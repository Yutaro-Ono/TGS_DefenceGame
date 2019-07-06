//-----------------------------------------------------------------------+
// エネミークラス                            
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "Enemy.h"

const VECTOR Enemy::SCALE_SIZE = { 0.3f, 0.3f, 0.3f };
const float Enemy::MOVE_SPEED = 3.0f;

// コンストラクタ
Enemy::Enemy(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_targetVec = VGet(0.0f, 0.0f, 0.0f);
}

// デストラクタ
Enemy::~Enemy()
{
}

// 各種初期化処理
void Enemy::Initialize()
{
	m_angle = GetRand(180);
}

void Enemy::Update(float deltaTime)
{
	// 角度を設定
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle / 180.0f * DX_PI_F, 0.0f));


	MV1SetPosition(m_modelHandle, m_position);
}

// 出現位置設定
void Enemy::SetEmergence(const VECTOR popPos)
{
	m_position = popPos;

	MV1SetScale(m_modelHandle, SCALE_SIZE);

	MV1SetPosition(m_modelHandle, m_position);
}

// ターゲットの方向に向く
void Enemy::GazeTarget(PlayerManager& playerManager, float deltaTime)
{
	Actor* player = playerManager.GetPlayerPointer();
	VECTOR pVec = player->GetPosition();
	// 目標までの距離検出
	m_targetVec.x = pVec.x - m_position.x;
	m_targetVec.z = pVec.z - m_position.z;

	// 角度と移動量を取得
	m_angle = atan2(m_targetVec.z, m_targetVec.x);

	m_position.x += cos(m_angle * MOVE_SPEED);
	m_position.z += sin(m_angle * MOVE_SPEED);
}
