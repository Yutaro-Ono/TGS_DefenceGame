#include "InterfacePlayer.h"

void InterfacePlayer::Initialize()
{
	// �̗̓Q�[�W�̃��[�h(�������邢�R�[�h)
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_1.png");
		}
		if (i == 1)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_2.png");
		}
		if (i == 2)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_3.png");
		}
		if (i == 3)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_4.png");
		}
		if (i == 4)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_5.png");
		}
	}

	// �̗̓t���[���̃��[�h
	hpFrame = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_Frame.png");
}

void InterfacePlayer::Update()
{
}

void InterfacePlayer::Update(Player & player)
{
}

void InterfacePlayer::Draw(Player& player)
{
	for (int i = 0; i < player.GetHitPoint(); i++)
	{
		DrawGraph(0, 0, hpGauge[i], TRUE);
	}

	DrawGraph(0, 0, hpFrame, TRUE);
}
