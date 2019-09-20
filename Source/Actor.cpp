//-----------------------------------------------------------------------+
// アクター基底クラス                                   
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "Actor.h"

// コンストラクタ
Actor::Actor(const int sourceModelHandle)
	:m_modelHandle(-1)
{
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);          // モデルを複製
}

// デストラクタ
Actor::~Actor()
{
	MV1DeleteModel(m_modelHandle);          // モデルを削除
}

// モデルの描画
void Actor::Draw()
{
	// 処理なし
}
