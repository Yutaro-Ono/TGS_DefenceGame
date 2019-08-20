//-----------------------------------------------------------------------+
// �I�u�W�F�N�g���N���X                                   
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "ObjectBase.h"

ObjectBase::ObjectBase(int sourceModelHandle)
{
	// �����̃��f�������g�̃n���h���ɕ���
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);
}

ObjectBase::~ObjectBase()
{
	MV1DeleteModel(m_modelHandle);
}

// �`�揈��
void ObjectBase::Draw()
{
	// ���f����`��
	MV1DrawModel(m_modelHandle);
	// �����蔻��m�F�p�̋���
	// DrawSphere3D(m_position, m_radius, 5, 0x00ffff, 0x00ffff, FALSE);
}