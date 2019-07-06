//-----------------------------------------------------------------------+
// スカイドームクラス                                   
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectSky.h"

const VECTOR ObjectSky::SCALE_SIZE = { 12.0f, 12.0f, 12.0f };
const VECTOR ObjectSky::ROTATE_RAD = { 15.0f * DX_PI_F / 180.0f, 0.0f, 0.0f };

ObjectSky::ObjectSky(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, -800.0f, -5000.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

ObjectSky::~ObjectSky()
{
}

void ObjectSky::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);                 // スケールの設定  ※元のモデルがあまりにも大きすぎるため縮小
	MV1SetRotationXYZ(m_modelHandle, ROTATE_RAD);           // 回転値の設定
	MV1SetPosition(m_modelHandle, m_position);
}
