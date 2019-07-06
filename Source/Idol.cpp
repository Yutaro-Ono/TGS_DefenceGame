//-----------------------------------------------------------------------+
// アイドル(護衛対象)クラス                            
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "Idol.h"

const VECTOR Idol::SCALE_SIZE = { 1.0f, 1.0f, 1.0f };

Idol::Idol(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
}

void Idol::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);
}

void Idol::Delete()
{
}

void Idol::Update(float deltaTime)
{
}
