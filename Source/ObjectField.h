//---------------------------------------------------------------+
// �t�B�[���h�I�u�W�F�N�g�N���X
//      : �t�B�[���h�̌ŗL���� (�I�u�W�F�N�g���N���X���p��)
//                                              2019 Yutaro Ono.
//---------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "ObjectBase.h"

class ObjectField : public ObjectBase
{

public:

	ObjectField(int sourceModelHandle);             // �R���X�g���N�^
	~ObjectField();                                 // �f�X�g���N�^

	void Initialize() override;                     // ����������

	void Update(float deltaTime) override;          // �X�V����


private:

	VERTEX3D     m_vertex[6];          // ���_���i�[

	static const VECTOR SCALE_SIZE;          // ���f���̊g�嗦

};