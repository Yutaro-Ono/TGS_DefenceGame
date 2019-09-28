//-----------------------------------------------------------+
// �J�����N���X
//      : �J�����̐ݒ�C�X�V���Ǘ�
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"

// �N���X�O���錾
class PlayerManager;

class Camera final
{

public:

	Camera();                                           // �R���X�g���N�^
	~Camera();                                          // �f�X�g���N�^

	void Update(PlayerManager& playerManager);          // �X�V����

	//---------------------------------------------------+
	// Getter/Setter �֘A
	//---------------------------------------------------+
	// �|�W�V�����̃Q�b�^�[/�Z�b�^�[
	const VECTOR& GetPos() const { return m_position; }


private:

	VECTOR     m_position;          // �|�W�V����

};