//-----------------------------------------------------------------------+
// スコアクラス                                 
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "Score.h"

const int Score::SCORE_POINT = 100;       // スコア加算用ポイント
const double Score::SCORE_MULTIPLE[5] = { 1, 2, 3, 3.5, 4 };

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
}

void Score::Delete()
{
	
}

// 更新処理
void Score::Update(Player& player)
{
	// プレイヤーの所持アイテムを追跡
	m_holdScore = player.GetHoldItem();

	// プレイヤーの回収フラグが立ったらスコアを加算し、フラグを折る
	if (player.GetDeliveredItem() == true)
	{
		// スコアに加算:プレイヤーの所持しているアイテム * 基本スコアポイント * 所持アイテム数による倍率
		m_score += player.GetHoldItem() * SCORE_POINT * SCORE_MULTIPLE[player.GetHoldItem() - 1];
		player.InitHoldItem();
		player.SetDeliveredItem(false);
	}
}

// 描画処理
void Score::Draw()
{
	// スコアの表示
	DrawFormatString(0, 450, GetColor(255, 255, 255), "%d", m_score);
	// ホールド状態のスコアを表示
	DrawFormatString(0, 500, GetColor(255, 255, 255), "%d", m_holdScore);
}
