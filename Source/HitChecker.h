//+-----------------------------------------------------------------+//
// �Փ˔���N���X
//      : �����蔻��(�v���C���[�C�I�u�W�F�N�g�C�G�l�~�[)
//                                        Last Update : 2019/07/02 
//+---------------------------------------------------------------+//
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"
#include "ObjectManager.h"

class HitChecker final
{
public:
	HitChecker();               // �R���X�g���N�^
	~HitChecker();              // �f�X�g���N�^

	static void CheckHit(PlayerManager& playerManager, ObjectManager& objectManager);

private:

};