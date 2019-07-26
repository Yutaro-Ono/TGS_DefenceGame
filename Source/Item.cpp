#include "Item.h"

const float Item::FALL_SPEED = 100.0f;

// コンストラクタ
Item::Item(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
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
	m_state = (int)Item::POP;

	
}

// 更新処理
void Item::Update()
{

}

// 出現時落下処理
void Item::Fall(float deltaTime)
{
	// 空中にある時に落下
	if (m_position.y < 0)
	{
		m_position.y += FALL_SPEED * deltaTime;
	}

}

// 描画処理
void Item::Draw()
{
}
