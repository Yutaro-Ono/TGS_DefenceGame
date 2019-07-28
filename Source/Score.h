//-----------------------------------------------------------+
// スコアクラス
//      : スコアの加算や描画などを管理するクラス
//                                  Last Update : 2019/07/28
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "PlayerManager.h"

class Score final
{
public:

	Score();
	~Score();

	void Initialize();

	void Update();

	void Draw();

	//--------------------------------------------------------+
    // Getter/Setter 関連
    //--------------------------------------------------------+
	// スコアのゲッター
	const int& GetScore() const { return m_score; }
	// スコアのセッター
	void SetScore(const int score) { m_score = SCORE_POINT * score; }

private:

	int m_score;                        // スコア

	static const int SCORE_POINT;       // スコアポイント(加算用)
};