//-----------------------------------------------------------------------+
// �Փ˔���N���X                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "HitChecker.h"
#include "Actor.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
HitChecker::HitChecker()
{

}

HitChecker::~HitChecker()
{
}

//--------------------------------------------------------------------------------------------------+
// �q�b�g�`�F�b�N���� �o�O����(while���[�v�����ȏ������烉���_���ȕ����ɒe�����̏������K�v)
//--------------------------------------------------------------------------------------------------+
void HitChecker::CheckHit(PlayerManager & playerManager, ObjectManager & objectManager)
{
	//Actor* player = playerManager.GetPlayerPointer();

	//// Z����X���̓񎟌����W�Ƃ��Ă����蔻����s��.
	//VECTOR yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
	//bool isHit = true;

	//// ��x�ł��Ԃ�������ʒu���ς��̂Ńq�b�g�v�Z�����Ȃ���.
	//while (isHit)
	//{
	//	isHit = false;
	//	for (int i = 0; i < LINE_OBSTRUCT_COL; i++)
	//	{
	//		for (int j = 0; j < LINE_OBSTRUCT_RAW; j++)
	//		{
	//			ObstructBase* obstruct = obstructManager.GetObstruct(j, i);
	//			if (obstruct != NULL)
	//			{
	//				VECTOR yZeroObstruct = VGet(obstruct->GetPos().x, 0, obstruct->GetPos().z);

	//				// ���݂��̃|�W�V�����Ɣ��a�̋������d�Ȃ����瓖�����Ă��邱�ƂɂȂ�.
	//				VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);

	//				//printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

	//				if (VSize(playerToObs) < player.GetHitRadius() + obstruct->GetHitRadius())
	//				{
	//					//printfDx("Hit!");
	//					player.OnHitObstruct(*obstruct);     // �v���C���[�̈ʒu�����炷�֐����Ăяo��(�I�u�W�F�N�g�͌Œ�)
	//					isHit = true;
	//					break;
	//				}
	//			}
	//		}
	//		// �q�b�g���Ă���v�Z���Ȃ���+�񎟌����W�Ƃ��Ẵv���C���[�̈ʒu���X�V.
	//		if (isHit)
	//		{
	//			yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);
	//			break;
	//		}
	//	}
	//}
}
