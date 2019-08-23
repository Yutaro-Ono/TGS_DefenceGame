//-----------------------------------------------------------------------+
// プレイヤークラス                        
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Player.h"
#include <math.h>

const int Player::MAX_HP = 5;
const float Player::MOVE_SPEED = 80.0f;
const float Player::INITIAL_POSITION_Y = 5.0f;
const VECTOR Player::SCALE_SIZE = { 0.03f, 0.03f, 0.03f };
const float Player::JUMP_POWER = 0.3f;
const float Player::JUMP_SUB = 1.0f;
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
	velocityY = 0.0f;
	m_holdItemNum = 0;
	m_deliverdItem = false;
	m_playEffect = false;

	// エフェクトのロード
	m_damageEffect = new PlayEffect("Data/Effects/Player_Damaged.efk");
	m_damageEffect->Initialize();
	m_getEffect = new PlayEffect("Data/Effects/Player_Cure.efk");
	m_getEffect->Initialize();
	m_delivereyEffect = new PlayEffect("Data/Effects/Player_StartLanding.efk");
	m_delivereyEffect->Initialize();

	// 効果音の生成
	m_getStarSound = new SoundFX("Data/Music/SE/Player/Get/コイン6.mp3");
	m_deliverySound = new SoundFX("Data/Music/SE/Player/Delivery/soundlogo6.mp3");
}

void Player::Delete()
{

	m_damageEffect->Delete();
	m_getEffect->Delete();
	m_delivereyEffect->Delete();
	m_getStarSound->Delete();
	m_deliverySound->Delete();

	delete (m_damageEffect);
	delete (m_getEffect);
	delete (m_delivereyEffect);
	delete (m_getStarSound);
	delete (m_deliverySound);

}

// 更新
void Player::Update(float deltaTime)
{
}

void Player::Update(Input& input, float deltaTime)
{
	VECTOR prevPosition;
	prevPosition = m_position;

	//-----------------------------------------//
    // 移動処理
    //----------------------------------------//
	if (input.GetLeftStickState(XINPUT_LSTICK::LSTICK_LEFT))
	{
		ChangeAngle();
		m_position.x -= MOVE_SPEED * deltaTime;
	}

	if (input.GetLeftStickState(XINPUT_LSTICK::LSTICK_RIGHT))
	{
		ChangeAngle();
		m_position.x += MOVE_SPEED * deltaTime;
	}

	if (input.GetLeftStickState(XINPUT_LSTICK::LSTICK_UP))
	{
		ChangeAngle();
		m_position.z += MOVE_SPEED * deltaTime;
	}

	if (input.GetLeftStickState(XINPUT_LSTICK::LSTICK_DOWN))
	{
		ChangeAngle();
		m_position.z -= MOVE_SPEED * deltaTime;
	}
	
	// いずれかのキーが押されている時
	if (prevPosition.x != m_position.x || prevPosition.z != m_position.z)
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

	// ポジションをセット
	MV1SetPosition(m_modelHandle, m_position);

	// 角度を設定
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle, 0.0f));
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


	// 当たり判定フラグが立ったらエフェクトを再生
	if (m_hitEnemy == true && m_damageEffect->GetNowPlaying() == -1)
	{
		m_damageEffect->PlayEffekseer(m_position);
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
		velocityY = 0.0f;
	}
	//if (m_moveFlag == true)
	//{
	//	m_position.y = velocityY;
	//	if (velocityY >= 0)
	//	{
	//		velocityY -= JUMP_SUB;
	//	}
	//	if (velocityY <= -100.0f)
	//	{
	//		velocityY += JUMP_SUB;
	//	}
	//}

	//if (m_moveFlag == false)
	//{
	//	velocityY = 0.0f;
	//}


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

// パッドの入力からプレイヤーの方向を調整する
void Player::ChangeAngle()
{
	// 左スティックの入力値を格納する
	int padX, padY;

	GetJoypadAnalogInput(&padX, &padY, DX_INPUT_PAD1);         // 左スティックの入力値を得る
	padY *= -1;                                                          // y軸を反転

	m_angle = atan2((float)padX / 1000.0f, (float)padY / 1000.0f);          // プレイヤーの角度を求める
	if (m_angle < 0)
	{
		m_angle += DX_PI_F * 2;
	}
}
