//-----------------------------------------------------------------------+
// アクター基底クラス                                   
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "Actor.h"

Actor::Actor(const int sourceModelHandle)
	:m_modelHandle(-1)
{
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);     // モデルを複製

	printfDx("モデルをロード\n");

}

Actor::~Actor()
{
	MV1DeleteModel(m_modelHandle);      // モデルを削除
}

// モデルの描画
void Actor::Draw()
{

	MV1DrawModel(m_modelHandle);

	// 当たり判定確認用の球
	DrawSphere3D(m_position, 3.0f, 5, 0x00ffff, 0x00ffff, FALSE);

	//printfDx("モデルを描画\n");
}
