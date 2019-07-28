#pragma once
#include "InterfaceBase.h"
#include "Player.h"

class InterfacePlayer : public InterfaceBase
{
public:

	void Initialize() override;

	void Update() override;

	void Update(Player& player);

	void Draw(Player& player);

private:

	// スコアアイテム所持数
	int m_holdItem;

	// 画像ハンドル関連
	int hpGauge[5];
	int hpFrame;

};