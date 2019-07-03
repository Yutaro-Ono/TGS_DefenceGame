//-----------------------------------------------------------+
// エネミークラス
//      : エネミーの固有処理
//                                  Last Update : 2019/07/03
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:

	enum STATE
	{
		NONE = 0,
		ACTIVE,
		DEAD,
	};

	Enemy(int sourceModelHandle);                    // コンストラクタ
	~Enemy();                                        // デストラクタ

	void Initialize() override;                      // 各種初期化処理

	void Emergence(const VECTOR popPos);             // 最初の出現位置設定

	void GazeTarget();                               // ターゲットの方向に向く
};