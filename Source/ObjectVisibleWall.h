//-----------------------------------------------------------+
// �����Ȃ��ǃN���X
//      : �t�B�[���h��̌����Ȃ���(����s�G���A�p)
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "ObjectBase.h"
#include "HitChecker.h"

class ObjectVisibleWall
{

public:

	ObjectVisibleWall();                   // �R���X�g���N�^
	~ObjectVisibleWall();                  // �f�X�g���N�^

	void Update(float deltaTime);          // �X�V����

	//-------------------------------------------------------------+
	// Getter/Setter�֘A
	//-------------------------------------------------------------+
	// �|�W�V�����̃Z�b�^�[
	void SetPosition(const VECTOR in_position) { m_position = in_position; }


private:

	VECTOR     m_position;          // �|�W�V����

};