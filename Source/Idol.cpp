//-----------------------------------------------------------------------+
// アイドル(護衛対象)クラス                            
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "Idol.h"

const VECTOR Idol::SCALE_SIZE = { 1.0f, 1.0f, 1.0f };

// コンストラクタ
Idol::Idol(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
}

// 初期化処理
void Idol::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);
}

// 解放処理
void Idol::Delete()
{
}

// 更新処理
void Idol::Update(float deltaTime)
{
}

// 描画処理
void Idol::Draw()
{
}
