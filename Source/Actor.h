//----------------------------------------------------------------------+
// �A�N�^�[���N���X
//      : �A�N�^�[(�ړ�����I�u�W�F�N�g�C�L�����N�^�[)
//                                                     2019 Yutaro Ono.
//----------------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "ObjectBase.h"

class Actor
{

public:

	Actor(const int sourceModelHandle);                // �R���X�g���N�^
	virtual ~Actor();                                  // �f�X�g���N�^

	virtual void Initialize() = 0;                     // ����������
	virtual void Delete() = 0;                         // �������

	virtual void Update(float deltaTime) = 0;          // �X�V����
	virtual void Draw() = 0;                           // �`�揈��

	//--------------------------------------------------------------------------+
    // Getter/Setter �֘A
    //--------------------------------------------------------------------------+
	// �|�W�V�����̃Q�b�^�[
	virtual const VECTOR& GetPosition() const { return m_position; }
	// �|�W�V�����̃Z�b�^�[
	virtual void SetPos(const VECTOR set) { m_position = set; }
	// ���a�̎擾(�����蔻��p)
	virtual const float& GetRadius() const = 0;


protected:

	VECTOR      m_position;          // �|�W�V����
	VECTOR     m_direction;          // ����

	float          m_angle;          // �p�x
	float      m_hitRadius;          // �����蔻��p�̔��a

	int      m_modelHandle;          // ���f���̃n���h��

};