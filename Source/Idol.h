//-----------------------------------------------------------+
// アイドル(護衛対象)クラス
//      : アイドルの固有処理
//                                  Last Update : 2019/07/02
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Actor.h"
#include "HitChecker.h"

class Idol : public Actor
{
public:

	Idol(int sourceModelHandle);
	~Idol() {};

	void Initialize() override;

	void Delete() override;

	void Update(float deltaTime) override;

private:

	static const VECTOR SCALE_SIZE;          // モデルの拡大率
};