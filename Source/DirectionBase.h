//-----------------------------------------------------------+
// �f�B���N�V����(���o)�x�[�X�N���X
//      : �Q�[�����̉��o�̊��N���X
//                                  Last Update : 2019/08/04
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"


class DirectionBase
{
public:

	DirectionBase();                       // �R���X�g���N�^
	~DirectionBase();                      // �f�X�g���N�^

	virtual void Initialize() = 0;         // �e�평����(�������z�֐�)

	// ���o�̏�Ԃ��擾����
	const bool& GetActive() const { return m_activate; }


private:

	bool m_activate;                       // ���̉��o���A�N�e�B�u���ǂ���


};