//-----------------------------------------------------------------------+
// アクター基底クラス                                   
//                                              Last Update : 2019/07/01
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


	printfDx("モデルを描画\n");
}
