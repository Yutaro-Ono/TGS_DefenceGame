//-----------------------------------------------------------+
// スコアクラス
//      : スコアの加算や描画などを管理するクラス
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "PlayerManager.h"
#include "TextGraph.h"
#include "Timer.h"

// クラス前方宣言
class TextGraph;
class Timer;

class Score final
{

public:

	Score();                                     // コンストラクタ
	~Score();                                    // デストラクタ

	void Initialize();                           // 初期化処理
	void Delete();                               // 解放処理

	void Update(Player& player);                 // 更新処理
	void Draw(TextGraph& text);                  // 描画処理

	void DrawAddScore(TextGraph& text);          // 加算スコアの描画

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
	VECTOR m_addPosition;                           // 取得したスコアの座標
	int m_addScoreVal;                              // スコア加算分
	bool m_addScore;                                // スコアが加算されたかどうか

	Timer* m_timer;                                 // タイマー


	static const int SCORE_POINT;                   // スコアポイント(加算用)
	static const double SCORE_MULTIPLE[6];          // 所持アイテム数によるスコア獲得倍率

};