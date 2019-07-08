//-----------------------------------------------------------------------+
// プレイヤークラス                        
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Player.h"

const float Player::MOVE_SPEED = 200.0f;
const float Player::INITIAL_POSITION_Y = 5.0f;
const VECTOR Player::SCALE_SIZE = { 0.05f, 0.05f, 0.05f };
const float Player::JUMP_POWER = 12.0f;
const float Player::JUMP_SUB = 0.3f;

// コンストラクタ(Actorの初期化子を付ける)
Player::Player(const int sourceModelHandle)
	:Actor(sourceModelHandle)
	,m_hitRadius(5.0f)
{
	m_moveFlag = false;
	m_position = VGet(0.0f, 5.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;
	velocityY = JUMP_POWER;
}

// デストラクター
Player::~Player()
{
	// 処理なし
}

// 更新
void Player::Update(Input& input, float deltaTime)
{

	//-----------------------------------------//
	// 移動処理
	//----------------------------------------//
	if (input.GetKeyPad() & PAD_INPUT_UP)
	{
		m_position.z += MOVE_SPEED * deltaTime;
		m_angle = 0.0f;
	}

	if (input.GetKeyPad() & PAD_INPUT_DOWN)
	{
		m_position.z -= MOVE_SPEED * deltaTime;
		m_angle = -180.0f;
	}

	if (input.GetKeyPad() & PAD_INPUT_LEFT)
	{
		m_position.x -= MOVE_SPEED * deltaTime;
		m_angle = -90.0f;
	}

	if (input.GetKeyPad() & PAD_INPUT_RIGHT)
	{
		m_position.x += MOVE_SPEED * deltaTime;
		m_angle = 90.0f;
	}

	// いずれかのキーが押されている時
	if (input.GetKeyPad() != 0)
	{
		if (m_moveFlag == false)
		{
			m_moveFlag = true;
		}
	}

	MotionMove(deltaTime);

	// モデルの拡大率セット
	MV1SetScale(m_modelHandle, SCALE_SIZE);

	// 角度を設定
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle / 180.0f * DX_PI_F, 0.0f));

	// ポジションをセット
	MV1SetPosition(m_modelHandle, m_position);

	//printfDx("pos : x = %f\ny = %f\nz = %f\n", m_position.x, m_position.y, m_position.z);
}

void Player::Draw()
{
	MV1DrawModel(m_modelHandle);

	// 当たり判定確認用の球
	DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
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

	if (m_moveFlag == false)
	{
		m_position.y = INITIAL_POSITION_Y;
		velocityY = JUMP_POWER;
	}

}

// エネミーとの当たり判定処理
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
