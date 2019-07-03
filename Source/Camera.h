//-----------------------------------------------------------+
// カメラクラス
//      : カメラの設定，更新を管理
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once

#include "DxLib.h"

class PlayerManager;

class Camera final
{
public:
	Camera();							// コンストラクタ.
	~Camera();							// デストラクタ.

	void Update(PlayerManager& playerManager);	// 更新.

	// ポジションのgetter/setter.
	const VECTOR& GetPos() const { return pos; }

private:
	VECTOR	pos;			// ポジション.

};