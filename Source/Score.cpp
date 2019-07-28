//-----------------------------------------------------------------------+
// スコアクラス                                 
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "Score.h"

const int Score::SCORE_POINT = 100;       // スコア加算用ポイント

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
}

// 更新処理
void Score::Update()
{

}

// 描画処理
void Score::Draw()
{
	// スコアの表示
	DrawFormatString(0, 500, GetColor(255, 255, 255), "%d", m_score);
}
