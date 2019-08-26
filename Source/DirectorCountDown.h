//--------------------------------------------------------------+
// カウントダウン系の演出総合クラス
//      : ゲーム開始時、インターバル時のカウントダウン演出処理
//                                  Last Update : 2019/08/04
//--------------------------------------------------------------+
#pragma once
#include "DirectorBase.h"
#include "Timer.h"
#include "GameSystem.h"

class Timer;

class CountDown : public DirectorBase
{
public:

	CountDown();
	~CountDown();

	void Initialize() override;       // 各種初期化処理

	void Delete() override;           // 各種解放処理

	void Draw();                      // 描画処理

	bool StartCountDown();            // ゲーム開始時のカウントダウン演出

	const int& GetTimeGraphNum(const int in_nowTime) const;        // タイマーに基づく画像番号のゲッター

private:

	int m_prevTime;              // 前回の更新時間
	int m_nowTime;               // 現在の更新時間

	int m_counterGraph[3];       // カウントダウンの描画用グラフィックハンドル

	Timer* m_timer;              // タイマークラス

	static const int MAX_START_TIME;       // 開始時の最大カウントダウン時間
};