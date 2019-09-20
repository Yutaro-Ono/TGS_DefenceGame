//-----------------------------------------------------------------------+
// エネミークラス                            
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "Enemy.h"

const VECTOR Enemy::SCALE_SIZE = { 0.3f, 0.3f, 0.3f };
const float Enemy::MOVE_SPEED = 93.0f;

// コンストラクタ
Enemy::Enemy(int sourceModelHandle)
	:Actor(sourceModelHandle)
	,m_hitRadius(10.0f)
	,m_hitPlayer(false)
{
	// 各種初期化
	m_position = VGet(0.0f, 0.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_hitTime = 0;
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
	
	// もし地面に埋まっていたら上に押し出す
	if (m_position.y < 0.0f)
	{
		m_position.y = 0.0f;
	}

	// モデルの位置を設定
	MV1SetPosition(m_modelHandle, m_position);
}

void Enemy::Draw()
{
	MV1DrawModel(m_modelHandle);
	// 当たり判定確認用の球
	//DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

// 出現位置設定
void Enemy::SetEmergence(const VECTOR popPos)
{
	m_position = popPos;

	// スケール(拡大率)の調整
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	
	// 描画する座標を設定
	MV1SetPosition(m_modelHandle, m_position);
}

void Enemy::HitInterval()
{
	// 当たり判定フラグが立ったら
	if (m_hitPlayer == true)
	{
		// 1.5秒たつまで
		if (GetNowCount() - m_hitTime >= 1500)
		{
			m_hitTime = 0.0f;
		}

		// インターバルが初期化されたら当たり判定フラグを解除する
		if (m_hitTime == 0.0f)
		{
			m_hitPlayer = false;
		}
	}
}

// 他のエネミーに当たった時
void Enemy::OnHitOtherEnemy(Enemy& other_enemy)
{
	// 自分自身の位置を障害物のあたり判定分ずらす.
    // Z軸とX軸の二次元座標として位置ずらしを行う.
	VECTOR yZeroPlayer = VGet(m_position.x, 0, m_position.z);
	VECTOR yZeroObstruct = VGet(other_enemy.GetPosition().x, 0, other_enemy.GetPosition().z);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// ぶつかったときに離す距離。ちょうどだとfloat誤差で重なり続けるので少し間をあける.
	float awayRange = (m_hitRadius + other_enemy.GetRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	m_position = VAdd(yZeroObstruct, awayVec);

}

// ターゲット(プレイヤー)の追跡処理
void Enemy::ChaseTarget(PlayerManager& playerManager, float deltaTime)
{
	// プレイヤーに当たった時はストップ
	if(m_hitPlayer == false)
	{
		Actor* player = playerManager.GetPlayerPointer();
		VECTOR pVec = player->GetPosition();
		// 目標までの距離検出
		m_targetVec.x = pVec.x - m_position.x;
		m_targetVec.z = pVec.z - m_position.z;

		// 角度と移動量を取得
		m_angle = atan2(m_targetVec.z, m_targetVec.x);

		m_position.x += cos(m_angle + MOVE_SPEED);
		m_position.z += sin(m_angle + MOVE_SPEED);
	}
}
