//-----------------------------------------------------------+
// �q�b�g�`�F�b�J�[(�Փ˔���)�N���X
//      : �I�u�W�F�N�g���m�������������ǂ��������o����
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ObjectManager.h"

class PlayerManager;
class EnemyManager;
class ObjectManager;

class HitChecker final
{
public:
	HitChecker();               // �R���X�g���N�^
	~HitChecker();              // �f�X�g���N�^

	// �v���C���[�ƃG�l�~�[���m�̓����蔻��`�F�b�J�[
	static void CheckHit(PlayerManager& playerManager, EnemyManager& enemyManager);
	// �G�l�~�[���m�̓����蔻��`�F�b�J�[
	static void CheckHitEnemy(EnemyManager& enemyManager, int enemy_num);

};