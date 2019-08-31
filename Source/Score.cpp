//-----------------------------------------------------------------------+
// スコアクラス                                 
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "Score.h"
#pragma warning(disable:4996)
const int Score::SCORE_POINT = 100;       // スコア加算用ポイント
const double Score::SCORE_MULTIPLE[6] = { 1, 2, 3, 3.5, 4, 5 };

Score::Score()
{
	// 処理なし
}

Score::~Score()
{
	// 処理なし
}

// 各種初期化処理
void Score::Initialize()
{
	m_score = 0;
	m_holdScore = 0;
	m_prevGetScoreValue = 0;
}

void Score::Delete()
{
	
}

// 更新処理
void Score::Update(Player& player)
{
	double score_multiple = 0.0;
	// プレイヤーの所持アイテムを追跡
	m_holdScore = player.GetHoldItem();

	// プレイヤーの回収フラグが立ったらスコアを加算し、フラグを折る
	if (player.GetDeliveredItem() == true)
	{
		// アイテム所持数が一定以上なら倍率を最大に設定
		if (player.GetHoldItem() >= 6)
		{
			score_multiple = SCORE_MULTIPLE[5];
		}
		else
		{
			score_multiple = SCORE_MULTIPLE[player.GetHoldItem() - 1];
		}

		// スコアに加算:プレイヤーの所持しているアイテム * 基本スコアポイント * 所持アイテム数による倍率
		m_score += player.GetHoldItem() * SCORE_POINT * score_multiple;

		player.InitHoldItem();
		player.SetDeliveredItem(false);
	}
}

// 描画処理
void Score::Draw(TextGraph& text)
{
	char score[15];
	sprintf(score, "%d", m_score);

	// SCORE:
	text.DrawTextMessage(1500, 0, "SCORE:");
	text.DrawTextMessage(1700, 0, score);
}
