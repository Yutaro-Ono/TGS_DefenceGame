//-----------------------------------------------------------+
// �J�����N���X
//      : �J�����̐ݒ�C�X�V���Ǘ�
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once

#include "DxLib.h"

class PlayerManager;

class Camera final
{
public:
	Camera();							// �R���X�g���N�^.
	~Camera();							// �f�X�g���N�^.

	void Update(PlayerManager& playerManager);	// �X�V.

	// �|�W�V������getter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR	pos;			// �|�W�V����.

};