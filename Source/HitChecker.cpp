//-----------------------------------------------------------------------+
// �Փ˔���N���X                    
//                                              Last Update : 2019/07/08
//-----------------------------------------------------------------------+
#include "HitChecker.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ObjectManager.h"

class EnemyManager;

HitChecker::HitChecker()
{

}

HitChecker::~HitChecker()
{
}

//--------------------------------------------------------------------------------------------------+
// �q�b�g�`�F�b�N���� �o�O����(while���[�v�����ȏ������烉���_���ȕ����ɒe�����̏������K�v)
//--------------------------------------------------------------------------------------------------+

// �v���C���[�ƃG�l�~�[
void HitChecker::CheckHit(PlayerManager & playerManager, EnemyManager& enemyManager)
{
	Player* player = playerManager.GetPlayerPointer();

	// Z����X���̓񎟌����W�Ƃ��Ă����蔻����s��.
	VECTOR yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
	bool isHit = true;

	// ��x�ł��Ԃ�������ʒu���ς��̂Ńq�b�g�v�Z�����Ȃ���.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < ALL_ENEMY; i++)
		{
			Enemy* enemy = enemyManager.GetEnemyPointer(i);
			if (enemy != NULL)
			{
				VECTOR yZeroEnemy = VGet(enemy->GetPosition().x, 0, enemy->GetPosition().z);

				// ���݂��̃|�W�V�����Ɣ��a�̋������d�Ȃ����瓖�����Ă��邱�ƂɂȂ�.
				VECTOR playerToObs = VSub(yZeroEnemy, yZeroPlayer);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(playerToObs) < player->GetRadius() + enemy->GetRadius())
				{
					printfDx("Hit!");
					enemy->SetHitPlayer(true);
					player->OnHitEnemy(*enemy);     // �v���C���[�̈ʒu�����炷�֐����Ăяo��(�I�u�W�F�N�g�͌Œ�)
					//isHit = true;
				}
				
				if (!(VSize(playerToObs) + 1.0f < player->GetRadius() + enemy->GetRadius()))
				{
					enemy->SetHitPlayer(false);
					break;
				}
			}
			// �q�b�g���Ă���v�Z���Ȃ���+�񎟌����W�Ƃ��Ẵv���C���[�̈ʒu���X�V.
			if (isHit)
			{
				yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
				break;
			}
		}
	}
}

void HitChecker::CheckHitEnemy(EnemyManager & enemyManager, int enemy_num)
{
	Enemy* main_enemy = enemyManager.GetEnemyPointer(enemy_num);

	// Z����X���̓񎟌����W�Ƃ��Ă����蔻����s��.
	VECTOR yZeroMainEnemy = VGet(main_enemy->GetPosition().x, 0, main_enemy->GetPosition().z);
	bool isHit = true;

	// ��x�ł��Ԃ�������ʒu���ς��̂Ńq�b�g�v�Z�����Ȃ���.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < ALL_ENEMY; i++)
		{
			Enemy* other_enemy = enemyManager.GetEnemyPointer(i);
			if (other_enemy != NULL && i != enemy_num)
			{
				VECTOR yZeroElseEnemy = VGet(other_enemy->GetPosition().x, 0, other_enemy->GetPosition().z);

				// ���݂��̃|�W�V�����Ɣ��a�̋������d�Ȃ����瓖�����Ă��邱�ƂɂȂ�.
				VECTOR mainEnemyToObs = VSub(yZeroElseEnemy, yZeroMainEnemy);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(mainEnemyToObs) < main_enemy->GetRadius() + other_enemy->GetRadius())
				{
					//printfDx("Hit!");
					main_enemy->OnHitOtherEnemy(*other_enemy);     // �v���C���[�̈ʒu�����炷�֐����Ăяo��(�I�u�W�F�N�g�͌Œ�)
					//isHit = true;
					break;
				}
			}
			// �q�b�g���Ă���v�Z���Ȃ���+�񎟌����W�Ƃ��Ẵv���C���[�̈ʒu���X�V.
			if (isHit)
			{
				yZeroMainEnemy = VGet(main_enemy->GetPosition().x, 0, main_enemy->GetPosition().z);
				break;
			}
		}
	}
}
