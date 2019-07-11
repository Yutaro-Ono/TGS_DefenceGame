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


	// ‰æ‘œƒnƒ“ƒhƒ‹ŠÖ˜A
	int hpGauge[5];
	int hpFrame;

};