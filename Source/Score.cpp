//-----------------------------------------------------------------------+
// スコアクラス                                 
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma warning(disable:4996)

// インクルードファイル
#include "Score.h"

const int Score::SCORE_POINT = 100;       // スコア加算用ポイント
const double Score::SCORE_MULTIPLE[6] = { 1, 2, 3, 3.5, 4, 5 };

// コンストラクタ
Score::Score()
{
	// 処理なし
}

// デストラクタ
Score::~Score()
{
	// 処理なし
}

// 各種初期化処理
void Score::Initialize()
{
	m_scorePosition = VGet(1700.0f, 20.0f, 0.0f);
	m_score = 0;
	m_holdScore = 0;

	m_addPosition = VGet(1650.0f, 60.0f, 0.0f);
	m_addScore = false;

	m_timer = new Timer();
	m_timer->Initialize();
}

// 解放処理
void Score::Delete()
{
	m_timer->Delete();
	m_timer->Initialize();
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
		// 取得したスコアは一時保存
		m_addScoreVal = player.GetHoldItem() * SCORE_POINT * score_multiple;
		// スコアの加算フラグをオン
		m_addScore = true;

		// スコアの初期化
		player.InitHoldItem();
		player.SetDeliveredItem(false);
	}
}

// 描画処理
void Score::Draw(TextGraph& text)
{
	char score[15];
	sprintf(score, "%d", m_score);

	// スコアの表示
	text.DrawTextMessage(1500, 20, "SCORE:");
	text.DrawTextMessage(m_scorePosition.x, m_scorePosition.y, score);
}

// 加算分スコアの表示
void Score::DrawAddScore(TextGraph& text)
{
	if (m_addScore == true)
	{
		char addScore[15];
		sprintf(addScore, "+%d", m_addScoreVal);

		// スコア加算分の表示
		text.DrawTextMessage(m_addPosition.x, m_addPosition.y, addScore);
		if (m_timer->RunTimer(1) < 0)
		{
			m_addScore = false;
		}
	}
	else
	{
		m_timer->Initialize();
	}
}
