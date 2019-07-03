//-----------------------------------------------------------+
// エネミークラス
//      : エネミーの固有処理
//                                  Last Update : 2019/07/02
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

	void SeeIdol();
};