//-----------------------------------------------------------------------+
// プレイヤークラス                        
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Player.h"

// コンストラクタ(Actorの初期化子を付ける)
Player::Player(const int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;

}

// デストラクター
Player::~Player()
{
	// 処理なし
}

// 更新
void Player::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//-----------------------------------------//
	// 移動処理
	//----------------------------------------//
	if (key & PAD_INPUT_UP)
	{
		m_position.z += 1.0f;
	}

	if (key & PAD_INPUT_DOWN)
	{
		m_position.z -= 1.0f;
	}

	if (key & PAD_INPUT_LEFT)
	{
		m_position.x -= 1.0f;
	}

	if (key & PAD_INPUT_RIGHT)
	{
		m_position.x += 1.0f;
	}

	// ポジションをセット
	MV1SetPosition(m_modelHandle, m_position);

	//printfDx("pos : x = %f\ny = %f\nz = %f\n", m_position.x, m_position.y, m_position.z);
}
