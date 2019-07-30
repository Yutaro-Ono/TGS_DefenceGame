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

	void Delete();

	void Update(Player& player);

	void Draw();

	//--------------------------------------------------------+
    // Getter/Setter 関連
    //--------------------------------------------------------+
	// スコアのゲッター
	const int& GetScore() const { return m_score; }

private:

	int m_score;                        // スコア

	int m_holdScore;                    // 所持中のスコア

	static const int SCORE_POINT;       // スコアポイント(加算用)
	static const double SCORE_MULTIPLE[6];                // 所持アイテム数によるスコア獲得倍率
};