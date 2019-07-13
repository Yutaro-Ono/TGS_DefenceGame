//-----------------------------------------------------------+
// �J�����N���X
//      : �J�����̐ݒ�C�X�V���Ǘ�
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"

class PlayerManager;

class Camera final
{
public:
	Camera();							// �R���X�g���N�^
	~Camera();							// �f�X�g���N�^

	// �X�V
	void Update(PlayerManager& playerManager);	

	//---------------------------------------------------+
	// Getter/Setter �֘A
	//---------------------------------------------------+
	// �|�W�V�����̃Q�b�^�[/�Z�b�^�[
	const VECTOR& GetPos() const { return m_position; }

private:

	VECTOR	m_position;			            // �|�W�V����

};