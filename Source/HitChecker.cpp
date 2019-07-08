//-----------------------------------------------------------------------+
// 衝突判定クラス                    
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
// ヒットチェック処理 バグあり(whileループが一定以上回ったらランダムな方向に弾く等の処理が必要)
//--------------------------------------------------------------------------------------------------+
void HitChecker::CheckHit(PlayerManager & playerManager, EnemyManager& enemyManager)
{
	Player* player = playerManager.GetPlayerPointer();

	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
	bool isHit = true;

	// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < ALL_ENEMY; i++)
		{
			Enemy* enemy = enemyManager.GetEnemyPointer(i);
			if (enemy != NULL)
			{
				VECTOR yZeroObstruct = VGet(enemy->GetPosition().x, 0, enemy->GetPosition().z);

				// お互いのポジションと半径の距離が重なったら当たっていることになる.
				VECTOR playerToObs = VSub(yZeroObstruct, yZeroPlayer);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(playerToObs) < player->GetRadius() + enemy->GetRadius())
				{
					printfDx("Hit!");
					player->OnHitEnemy(*enemy);     // プレイヤーの位置をずらす関数を呼び出す(オブジェクトは固定)
					//isHit = true;
					break;
				}
			}
			// ヒットしてたら計算やりなおし+二次元座標としてのプレイヤーの位置を更新.
			if (isHit)
			{
				yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
				break;
			}
		}
	}
}
