//-----------------------------------------------------------------------+
// タイマークラス                        
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Timer.h"
#include <iostream>

Timer::Timer()
	:m_countTimer(0)
	,m_startTimer(0)
	,m_prevTimer(0)
{

}

Timer::~Timer()
{

}

void Timer::Initialize()
{
	m_limitTime = 0;
	m_countTimer = 0;
	m_startTimer = GetNowCount() / 1000;
	m_prevTimer = m_startTimer;
}

void Timer::Delete()
{
}

void Timer::CountUp()
{
	// 未作成
}

void Timer::UpdateCountDown(const int in_maxTime)
{
	// 制限時間を入力したかどうか
	bool in_Timer = false;

	// 制限時間に入力していなかったら、制限時間に設定した時間を入力
	if (in_Timer == 0)
	{
		m_limitTime = in_maxTime;
		in_Timer = true;
	}

	// カウントダウンタイマーを取得
	m_countTimer = m_limitTime - ((GetNowCount() / 1000) - m_startTimer);

	// prevTimerを更新
	if ((m_prevTimer - m_countTimer) >= 1)
	{
		m_prevTimer = m_countTimer;
	}
}

void Timer::Draw()
{
	DrawFormatString(1100, 0, GetColor(255, 255, 255), "制限時間：%d", m_countTimer);
}
