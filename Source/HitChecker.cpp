//-----------------------------------------------------------------------+
// 衝突判定クラス                    
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "HitChecker.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ObjectManager.h"

class EnemyManager;

// コンストラクタ
HitChecker::HitChecker()
{
	// 処理なし
}

// デストラクタ
HitChecker::~HitChecker()
{
	// 処理なし
}

//--------------------------------------------------------------------------------------------------+
// 衝突チェック処理 バグあり(whileループが一定以上回ったらランダムな方向に弾く等の処理が必要)
//--------------------------------------------------------------------------------------------------+
// プレイヤーとエネミー
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
		for (int i = 0; i < enemyManager.GetActiveEnemy(); i++)
		{
			Enemy* enemy = enemyManager.GetEnemyPointer(i);
			if (enemy != NULL)
			{
				VECTOR yZeroEnemy = VGet(enemy->GetPosition().x, 0, enemy->GetPosition().z);

				// お互いのポジションと半径の距離が重なったら当たっていることになる.
				VECTOR playerToObs = VSub(yZeroEnemy, yZeroPlayer);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(playerToObs) < player->GetRadius() + enemy->GetRadius())
				{
					if (enemy->GetHitPlayer() == false)
					{
						enemy->SetInterval(GetNowCount());        // インターバルをセット
						enemy->SetHitPlayer(true);
					}
					// プレイヤーが他のエネミーに当たっていなければ
					if (player->GetHitEnemy() == false)
					{
						// printfDx("Hit!");
						player->SetDamaged();
						player->SetInterval(GetNowCount());
						player->OnHitEnemy(*enemy);     // プレイヤーの位置をずらす関数を呼び出す(オブジェクトは固定)
						player->SetHitEnemy(true);
					}
					isHit = true;
				}
				//if (!(VSize(playerToObs) + 1.0f < player->GetRadius() + enemy->GetRadius()))
				//{
				//	enemy->SetHitPlayer(false);
				//	break;
				//}
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

void HitChecker::CheckHitEnemy(EnemyManager & enemyManager, int enemy_num)
{
	Enemy* main_enemy = enemyManager.GetEnemyPointer(enemy_num);

	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroMainEnemy = VGet(main_enemy->GetPosition().x, 0, main_enemy->GetPosition().z);
	bool isHit = true;

	// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < enemyManager.GetActiveEnemy(); i++)
		{
			Enemy* other_enemy = enemyManager.GetEnemyPointer(i);
			if (other_enemy != NULL && i != enemy_num)
			{
				VECTOR yZeroElseEnemy = VGet(other_enemy->GetPosition().x, 0, other_enemy->GetPosition().z);

				// お互いのポジションと半径の距離が重なったら当たっていることになる.
				VECTOR mainEnemyToObs = VSub(yZeroElseEnemy, yZeroMainEnemy);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(mainEnemyToObs) < main_enemy->GetRadius() + other_enemy->GetRadius())
				{
					//printfDx("Hit!");
					main_enemy->OnHitOtherEnemy(*other_enemy);     // プレイヤーの位置をずらす関数を呼び出す(オブジェクトは固定)
					//isHit = true;
					break;
				}
			}
			// ヒットしてたら計算やりなおし+二次元座標としてのプレイヤーの位置を更新.
			if (isHit)
			{
				yZeroMainEnemy = VGet(main_enemy->GetPosition().x, 0, main_enemy->GetPosition().z);
				break;
			}
		}
	}
}

// プレイヤーとアイテム
void HitChecker::CheckHitItem(PlayerManager & playerManager, ItemManager & itemManager)
{
	Player* player = playerManager.GetPlayerPointer();

	// Z軸とX軸の二次元座標としてあたり判定を行う.
	VECTOR yZeroPlayer = VGet(player->GetPosition().x, 0, player->GetPosition().z);
	bool isHit = true;

	// 一度でもぶつかったら位置が変わるのでヒット計算をしなおす.
	while (isHit)
	{
		isHit = false;
		for (int i = 0; i < itemManager.GetActiveItem(); i++)
		{
			Item* item = itemManager.GetItemPointer(i);
			if (item != NULL)
			{
				VECTOR yZeroItem = VGet(item->GetPosition().x, 0, item->GetPosition().z);

				// お互いのポジションと半径の距離が重なったら当たっていることになる.
				VECTOR playerToObs = VSub(yZeroItem, yZeroPlayer);

				// printfDx("playerToObs:%f %f %f\n", playerToObs.x, playerToObs.y, playerToObs.z);

				if (VSize(playerToObs) < player->GetRadius() + item->GetRadius())
				{

					// プレイヤーの所持アイテムを加算し、アイテムが有効状態であれば無効に
					if (item->GetState() == Item::ACTIVE)
					{
						// printfDx("アイテムにHIT");
						player->AddHoldItem();                // プレイヤーのアイテム所持数を加算
						item->SetDeactive();                  // アイテムを無効状態に
					}

					
					isHit = true;
				}
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
