//-----------------------------------------------------------+
// タイマークラス
//      : 制限時間処理などに用いるタイマー
//                                  Last Update : 2019/09/03
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "SceneInGame.h"
#include "TextGraph.h"

class TextGraph;

class Timer
{
public:

	Timer();
	~Timer();                                     // デストラクタ

	void Initialize();                            // タイマーの初期化

	void Delete();                                // タイマーの削除

	void CountUp();                               // タイマーの計測(カウントアップ式)

	void UpdateCountDown(const int in_maxTime);         // タイマーの計測(カウントダウン)

	void Draw(TextGraph& text);                                  // タイマーの描画

	const int& GetTimer() const { return m_countTimer; }     // カウントタイマーのゲッター

	const int& GetLimitTime() const { return m_limitTime; }  // 制限時間のゲッター

	const int& GetPrevTimer() const { return m_prevTimer; }  // 一秒前のタイマーゲッター

	const int& RunTimer(const int in_limit);

private:

	bool m_isInsert;        // 制限時間をセットしたかどうか

	int m_countTimer;       // カウントダウン用タイマー

	int m_startTimer;       // スタート時タイマー

	int m_limitTime;        // 制限時間

	int m_prevTimer;        // 前のタイマー

};
