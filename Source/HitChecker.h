//-----------------------------------------------------------+
// ヒットチェッカー(衝突判定)クラス
//      : オブジェクト同士が当たったかどうかを検出する
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include "ObjectManager.h"

class PlayerManager;
class EnemyManager;
class ItemManager;
class ObjectManager;

class HitChecker final
{
public:
	HitChecker();               // コンストラクタ
	~HitChecker();              // デストラクタ

	// プレイヤーとエネミー同士の当たり判定チェッカー
	static void CheckHit(PlayerManager& playerManager, EnemyManager& enemyManager);
	// エネミー同士の当たり判定チェッカー
	static void CheckHitEnemy(EnemyManager& enemyManager, int enemy_num);
	// プレイヤーとアイテムの当たり判定チェッカー
	static void CheckHitItem(PlayerManager& playerManager, ItemManager& itemManager);
	// プレイヤーと回収ポッドの当たり判定
	static void CheckHitPod(PlayerManager& playerManager, ObjectManager& objectManager);
};