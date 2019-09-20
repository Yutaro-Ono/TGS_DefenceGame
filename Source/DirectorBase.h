//-----------------------------------------------------------+
// �f�B���N�V����(���o)�x�[�X�N���X
//      : �Q�[�����̉��o�̊��N���X
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"

class DirectorBase
{

public:

	DirectorBase();                         // �R���X�g���N�^
	~DirectorBase();                        // �f�X�g���N�^

	virtual void Initialize() = 0;          // �e�평����(�������z�֐�)
	virtual void Delete() = 0;              // �e��������(�������z�֐�)

	//--------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------+
	// ���o�̏�Ԃ��擾����
	const bool& GetActive() const { return m_activate; }


protected:

	bool m_activate;                       // ���̉��o���A�N�e�B�u���ǂ���

};