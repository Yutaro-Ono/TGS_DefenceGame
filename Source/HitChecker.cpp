//-----------------------------------------------------------------------+
// 衝突判定クラス                    
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
// ヒットチェック処理 バグあり(whileループが一定以上回ったらランダムな方向に弾く等の処理が必要)
//--------------------------------------------------------------------------------------------------+
void HitChecker::CheckHit(PlayerManager & playerManager, ObjectManager & objectManager)
{
	//Actor* player = playerManager.GetPlayerPointer();

	//// Z軸とX軸の二次元座標としてあたり判定を行う.
	//VECTOR yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
	//bool isHit = true;

	//// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
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

	//				// お互いのポジションと半径の距離が重なったら当たっていることになる.
	//				VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);

	//				//printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

	//				if (VSize(playerToObs) < player.GetHitRadius() + obstruct->GetHitRadius())
	//				{
	//					//printfDx("Hit!");
	//					player.OnHitObstruct(*obstruct);     // プレイヤーの位置をずらす関数を呼び出す(オブジェクトは固定)
	//					isHit = true;
	//					break;
	//				}
	//			}
	//		}
	//		// ヒットしてたら計算やりなおし+二次元座標としてのプレイヤーの位置を更新.
	//		if (isHit)
	//		{
	//			yZeroPlayer = VGet(player.GetPos().x, 0, player.GetPos().z);
	//			break;
	//		}
	//	}
	//}
}
