//+-----------------------------------------------------------------+//
// 衝突判定クラス
//      : 当たり判定(プレイヤー，オブジェクト，エネミー)
//                                        Last Update : 2019/07/02 
//+---------------------------------------------------------------+//
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"
#include "ObjectManager.h"

class HitChecker final
{
public:
	HitChecker();               // コンストラクタ
	~HitChecker();              // デストラクタ

	static void CheckHit(PlayerManager& playerManager, ObjectManager& objectManager);

private:

};