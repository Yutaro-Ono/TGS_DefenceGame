//-----------------------------------------------------------+
// �I�u�W�F�N�g���N���X
//      : �I�u�W�F�N�g�֘A(��Ƀt�B�[���h�\����)
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"

class ObjectBase
{

public:

	ObjectBase(int sourceModelHandle);                 // �R���X�g���N�^
	virtual ~ObjectBase();                             // �f�X�g���N�^

	virtual void Initialize() = 0;                     // ����������

	virtual void Update(float deltaTime) = 0;          // �X�V����

	virtual void Draw();                               // �`�揈��

	//-------------------------------------------------------------+
	// Getter/Setter�֘A
	//-------------------------------------------------------------+
	// �|�W�V�����̃Q�b�^�[
	const VECTOR& GetPosition() const { return m_position; };
	// �|�W�V�����̃Z�b�^�[
	void SetPos(const VECTOR set) { m_position = set; }
	// ���a�̎擾(�����蔻��p)
	const float& GetRadius() const{ return m_radius; }

protected:

	VECTOR      m_position;          // �|�W�V����
	VECTOR     m_direction;          // ����
	float         m_radius;          // ���a

	int      m_modelHandle;          // ���f���̃n���h��

};