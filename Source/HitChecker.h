//-----------------------------------------------------------+
// �q�b�g�`�F�b�J�[(�Փ˔���)�N���X
//      : �I�u�W�F�N�g���m�������������ǂ��������o����
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
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