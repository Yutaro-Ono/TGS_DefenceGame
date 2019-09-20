//-----------------------------------------------------------+
// アイテムクラス
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+

// インクルードファイル
#include "Item.h"

const float Item::FALL_SPEED = 50.0f;

// コンストラクタ
Item::Item(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	// 処理なし
}

// デストラクタ
Item::~Item()
{
	// 処理なし
}

// 各種初期化処理
void Item::Initialize()
{
	// 回転角度の初期化
	m_direction = VGet(-45.0f, 0.0f, 0.0f);
	// 半径を設定
	m_radius = 3.0f;
	// 状態をアクティブに
	m_state = Item::POP;
	// モデルの回転角度を設定
	MV1SetRotationXYZ(m_modelHandle, m_direction);
}

// 更新処理
void Item::Update(float deltaTime)
{
	// ポジションを設定
	MV1SetPosition(m_modelHandle, m_position);

	// モデルを回転させる
	MV1SetRotationXYZ(m_modelHandle, VGet(m_direction.x, m_direction.y, m_direction.z));

	// 回転角度を更新
	m_direction.y += 1.0f * deltaTime;
}

// 出現時落下処理
void Item::Fall(float deltaTime)
{
	// 空中にある時に落下
	if (m_position.y >= 1.0f)
	{
		m_position.y -= FALL_SPEED * deltaTime;
	}

	// 座標が一定値以下でアクティブに
	if (m_position.y <= 1.0f)
	{
		m_state = Item::ACTIVE;
	}
}

// 描画処理
void Item::Draw()
{
	// モデルを描画
	MV1DrawModel(m_modelHandle);
	// 当たり判定確認用の球
	DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

