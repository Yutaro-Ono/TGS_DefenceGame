//-----------------------------------------------------------+
// スコアクラス
//      : スコアの加算や描画などを管理するクラス
//                                  Last Update : 2019/07/28
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"
#include "TextGraph.h"
#include "Timer.h"

class TextGraph;
class Timer;

class Score final
{
public:

	Score();
	~Score();

	void Initialize();

	void Delete();

	void Update(Player& player);

	void Draw(TextGraph& text);

	void DrawAddScore(TextGraph& text);

	//--------------------------------------------------------+
    // Getter/Setter 関連
    //--------------------------------------------------------+
	// スコアのゲッター
	const int& GetScore() const { return m_score; }
	// スコア加算フラグのゲッター
	const bool& GetAddScore() const { return m_addScore; }


private:

	//----------------------------------------------------------------------------------//
	// スコア表示用
	//---------------------------------------------------------------------------------//
	VECTOR m_scorePosition;             // スコアのポジション
	int m_score;                        // スコア
	int m_holdScore;                    // 所持中のスコア	


	//---------------------------------------------------------------------------------//
	// スコア加算の表示関連
	//--------------------------------------------------------------------------------//
	VECTOR m_addPosition;                     // 取得したスコアの座標
	int m_addScoreVal;                        // スコア加算分
	bool m_addScore;                         // スコアが加算されたかどうか

	Timer* m_timer;                          // タイマー

	static const int SCORE_POINT;       // スコアポイント(加算用)
	static const double SCORE_MULTIPLE[6];                // 所持アイテム数によるスコア獲得倍率
};