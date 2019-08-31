#include "InterfacePlayer.h"

#pragma warning (disable:4996)

InterfacePlayer::InterfacePlayer()
{
}

InterfacePlayer::~InterfacePlayer()
{
}

// 初期化処理
void InterfacePlayer::Initialize()
{
	// 体力ゲージのロード(かったるいコード)
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

	// 体力フレームのロード
	hpFrame = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_Frame.png");

	// 座標関連の初期化
	m_scorePosition = VGet(0.0f, 0.0f, 0.0f);
	m_stockPosition = VGet(0.0f, 0.0f, 0.0f);
}

void InterfacePlayer::Delete()
{
}

void InterfacePlayer::Update()
{
}

void InterfacePlayer::Update(Player & player)
{
	// プレイヤーの座標を追跡
	m_stockPosition = ConvWorldPosToScreenPos(player.GetPosition());

	// プレイヤーの所持アイテム数を更新
	m_holdItem = player.GetHoldItem();
}

// 描画処理
void InterfacePlayer::Draw(Player& player, TextGraph& text)
{
	for (int i = 0; i < player.GetHitPoint(); i++)
	{
		DrawGraph(0, 20, hpGauge[i], TRUE);
	}

	DrawGraph(0, 20, hpFrame, TRUE);

	//---------------------------------------------------------------------------------------+
	// スコア関連描画
	//---------------------------------------------------------------------------------------+
	// ストック中のスコア
	char item[5];
	sprintf(item, "+%d", m_holdItem);
	// アイテム所持数が1~99の時にプレイヤーの頭上に表示
	if (m_holdItem > 0 && m_holdItem < 100)
	{
		text.DrawTextMessage(m_stockPosition.x - 60.0f, m_stockPosition.y - 110.0f, item);
	}
	// 所持アイテムが100個(上限)に到達したらMAX表示
	if (m_holdItem == 100)
	{
		text.DrawTextMessage(m_stockPosition.x - 60.0f, m_stockPosition.y - 110.0f, "MAX");
	}

}
