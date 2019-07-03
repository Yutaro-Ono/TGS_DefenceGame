//-----------------------------------------------------------------------+
// オブジェクト基底クラス                                   
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "ObjectBase.h"

ObjectBase::ObjectBase(int sourceModelHandle)
{
	// 引数のモデルを自身のハンドルに複製
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);
}

ObjectBase::~ObjectBase()
{
	MV1DeleteModel(m_modelHandle);
}

void ObjectBase::Draw()
{
	MV1DrawModel(m_modelHandle);
}

const VECTOR & ObjectBase::GetPosition() const
{
	return m_position;
}
