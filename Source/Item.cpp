#include "Item.h"

const float Item::FALL_SPEED = 50.0f;

// コンストラクタ
Item::Item(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
	,m_hitRadius(3.0f)
{
	
}

// デストラクタ
Item::~Item()
{
}

// 各種初期化処理
void Item::Initialize()
{
	// 状態をアクティブに
	m_state = Item::POP;

}

// 更新処理
void Item::Update()
{
	MV1SetPosition(m_modelHandle, m_position);
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
	MV1DrawModel(m_modelHandle);
	// 当たり判定確認用の球
	DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

