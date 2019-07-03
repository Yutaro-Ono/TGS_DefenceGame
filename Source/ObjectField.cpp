//-----------------------------------------------------------------------+
// フィールドオブジェクトクラス                                 
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "ObjectField.h"

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
	MV1SetPosition(m_modelHandle, m_position);
}

void ObjectField::Update()
{
}
