//-----------------------------------------------------------------------+
// プレイヤークラス                        
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Player.h"

const int Player::MAX_HP = 5;
const float Player::MOVE_SPEED = 80.0f;
const float Player::INITIAL_POSITION_Y = 5.0f;
const VECTOR Player::SCALE_SIZE = { 0.03f, 0.03f, 0.03f };
const float Player::JUMP_POWER = 12.0f;
const float Player::JUMP_SUB = 0.3f;
const int Player::MAX_HOLDITEM = 100;

// コンストラクタ(Actorの初期化子を付ける)
Player::Player(const int sourceModelHandle)
	:Actor(sourceModelHandle)
	,m_hitRadius(3.0f)
{

}

// デストラクター
Player::~Player()
{
	// 処理なし
}

void Player::Initialize()
{
	// 各種初期化
	m_hitPoint = MAX_HP;
	m_moveFlag = false;
	m_hitEnemy = false;
	m_position = VGet(0.0f, 5.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;
	m_hitTime = 0;
	velocityY = JUMP_POWER;
	m_holdItemNum = 0;
	m_deliverdItem = false;
}

// 更新
void Player::Update(float deltaTime)
{

	//-----------------------------------------//
	// 移動処理
	//----------------------------------------//
	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_UP)
	{
		m_position.z += MOVE_SPEED * deltaTime;
		m_angle = 0.0f;
	}

	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_DOWN)
	{
		m_position.z -= MOVE_SPEED * deltaTime;
		m_angle = -180.0f;
	}

	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_LEFT)
	{
		m_position.x -= MOVE_SPEED * deltaTime;
		m_angle = -90.0f;
	}

	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_RIGHT)
	{
		m_position.x += MOVE_SPEED * deltaTime;
		m_angle = 90.0f;
	}

	// いずれかのキーが押されている時
	if (INPUT_INSTANCE.GetKeyPad() != 0)
	{
		if (m_moveFlag == false)
		{
			m_moveFlag = true;
		}
	}

	// 簡易的なフィールド当たり判定処理(フィールドからはみ出したら戻す)
	HitWallUpdate(deltaTime);

	// 移動モーション
	MotionMove(deltaTime);

	// 当たり判定のインターバル処理
	HitInterval();

	// モデルの拡大率セット
	MV1SetScale(m_modelHandle, SCALE_SIZE);

	// 角度を設定
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle / 180.0f * DX_PI_F, 0.0f));

	// ポジションをセット
	MV1SetPosition(m_modelHandle, m_position);

	//printfDx("pos : x = %f\ny = %f\nz = %f\n", m_position.x, m_position.y, m_position.z);
}


// 簡易的なフィールドの当たり判定
void Player::HitWallUpdate(float deltaTime)
{
	if (m_position.x >= 110.0f)
	{
		m_position.x -= MOVE_SPEED * deltaTime;
	}
	if (m_position.x <= -110.0f)
	{
		m_position.x += MOVE_SPEED * deltaTime;
	}

	if (m_position.z >= 90.0f)
	{
		m_position.z -= MOVE_SPEED * deltaTime;
	}
	if (m_position.z <= -90.0f)
	{
		m_position.z += MOVE_SPEED * deltaTime;
	}
}

// 描画処理
void Player::Draw()
{
	// エネミーに当たった時の点滅処理
	if (m_hitEnemy == false || (GetNowCount() - m_hitTime) % 9)
	{
		// モデルの描画
		MV1DrawModel(m_modelHandle);
	}

	// 当たり判定確認用の球
	//DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

// 移動モーションにおける小刻みなジャンプモーション
void Player::MotionMove(float deltaTime)
{
	if (m_moveFlag == true)
	{
		m_position.y = velocityY;
		velocityY -= JUMP_SUB;
		if (velocityY <= INITIAL_POSITION_Y)
		{
			m_moveFlag = false;
		}
	}
	// 移動していないとき元のY座標に戻し、Y軸加速度を初期化
	if (m_moveFlag == false)
	{
		m_position.y = INITIAL_POSITION_Y;
		velocityY = JUMP_POWER;
	}

}

// エネミーに当たった時の処理
void Player::OnHitEnemy(Enemy & enemy)
{
	// 自分自身の位置を障害物のあたり判定分ずらす.
    // Z軸とX軸の二次元座標として位置ずらしを行う.
	VECTOR yZeroPlayer = VGet(m_position.x, 0, m_position.z);
	VECTOR yZeroObstruct = VGet(enemy.GetPosition().x, 0, enemy.GetPosition().z);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// ぶつかったときに離す距離。ちょうどだとfloat誤差で重なり続けるので少し間をあける.
	float awayRange = (m_hitRadius + enemy.GetRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	m_position = VAdd(yZeroObstruct, awayVec);

}

// エネミー衝突時、次の当たり判定処理が行われるまでのインターバル
void Player::HitInterval()
{
	if (m_hitEnemy == true)
	{
		// 1.5秒後にインターバル解除
		if (GetNowCount() - m_hitTime >= 2000)
		{
			m_hitTime = 0.0f;
		}

		// インターバルが初期化されたら当たり判定フラグを解除する
		if (m_hitTime == 0.0f)
		{
			m_hitEnemy = false;
		}
	}
}
