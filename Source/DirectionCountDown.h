//--------------------------------------------------------------+
// カウントダウン系の演出総合クラス
//      : ゲーム開始時、インターバル時のカウントダウン演出処理
//                                  Last Update : 2019/08/04
//--------------------------------------------------------------+
#pragma once
#include "DirectionBase.h"
#include "Timer.h"

class CountDown : public DirectionBase
{
public:

	CountDown();
	~CountDown();

	void Initialize() override;

	void StartCountDown();

private:

	int m_prevTick;              // 前回の更新時間
	int m_nowTick;               // 現在の更新時間

	Timer* m_timer;              // タイマークラス
};