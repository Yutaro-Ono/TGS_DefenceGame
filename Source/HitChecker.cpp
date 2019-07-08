//-----------------------------------------------------------------------+
// �Փ˔���N���X                    
//                                              Last Update : 2019/07/02
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
				VECTOR yZeroObstruct = VGet(enemy->GetPosition().x, 0, enemy->GetPosition().z);

				// ���݂��̃|�W�V�����Ɣ��a�̋������d�Ȃ����瓖�����Ă��邱�ƂɂȂ�.
				VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(playerToObs) < player->GetRadius() + enemy->GetRadius())
				{
					printfDx("Hit!");
					player->OnHitEnemy(*enemy);     // �v���C���[�̈ʒu�����炷�֐����Ăяo��(�I�u�W�F�N�g�͌Œ�)
					//isHit = true;
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
