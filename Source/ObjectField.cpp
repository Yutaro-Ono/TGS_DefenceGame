//-----------------------------------------------------------------------+
// フィールドオブジェクトクラス                                 
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectField.h"

//const VECTOR ObjectField::SCALE_SIZE = { 1.8f, 1.5f, 1.8f };      // モデルの拡大率
const VECTOR ObjectField::SCALE_SIZE = { 0.5f, 0.5f, 0.5f };      // モデルの拡大率

ObjectField::ObjectField(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

ObjectField::~ObjectField()
{
}

void ObjectField::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);
}

void ObjectField::Update()
{
}
