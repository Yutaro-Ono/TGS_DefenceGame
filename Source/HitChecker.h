//-----------------------------------------------------------+
// ヒットチェッカー(衝突判定)クラス
//      : オブジェクト同士が当たったかどうかを検出する
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
	HitChecker();               // コンストラクタ
	~HitChecker();              // デストラクタ

	// プレイヤーとエネミー同士の当たり判定チェッカー
	static void CheckHit(PlayerManager& playerManager, EnemyManager& enemyManager);
	// エネミー同士の当たり判定チェッカー
	static void CheckHitEnemy(EnemyManager& enemyManager, int enemy_num);

};