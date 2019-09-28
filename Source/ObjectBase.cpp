//-----------------------------------------------------------------------+
// �I�u�W�F�N�g���N���X                                   
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "ObjectBase.h"

// �R���X�g���N�^
ObjectBase::ObjectBase(int sourceModelHandle)
{
	// �����̃��f�������g�̃n���h���ɕ���
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);
}

// �f�X�g���N�^
ObjectBase::~ObjectBase()
{
	// ���f���̍폜
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