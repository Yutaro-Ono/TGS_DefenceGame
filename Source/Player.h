//-----------------------------------------------------------+
// プレイヤークラス
//      : プレイヤーの固有処理 (アクタークラスを継承)
//                                  Last Update : 2019/07/02
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Input.h"

class Player : public Actor
{
public:
	Player(const int sourceModelHandle);   // コンストラクタ
	~Player();                             // デストラクタ

	void Initialize() override {};

	void Delete() override {};

	void Update() override;     // プレイヤー関連の更新


private:

};

