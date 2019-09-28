//-----------------------------------------------------------------------+
// タイマークラス                        
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma warning(disable:4996)

// インクルードファイル
#include "Timer.h"
#include <iostream>

// コンストラクタ
Timer::Timer()
	:m_countTimer(0)
	,m_startTimer(0)
	,m_prevTimer(0)
{
	// 処理なし
}

// デストラクタ
Timer::~Timer()
{
	// 処理なし
}

// 初期化処理
void Timer::Initialize()
{
	m_isInsert = false;
	m_limitTime = 0;
	m_countTimer = 0;
	m_startTimer = GetNowCount();
	m_prevTimer = m_startTimer;
}

// 解放処理
void Timer::Delete()
{
	// 処理なし
}

// カウントアップ処理
void Timer::CountUp()
{
	// 未実装
}

// カウントダウン処理の更新
void Timer::UpdateCountDown(const int in_maxTime)
{
	// 制限時間を入力したかどうか
	bool in_Timer = false;

	// 制限時間に入力していなかったら、制限時間に設定した時間を入力
	if (in_Timer == false)
	{
		m_limitTime = in_maxTime;
		in_Timer = true;
	}

	// カウントダウンタイマーを取得
	m_countTimer = m_limitTime - ((GetNowCount() - m_startTimer) / 1000);

	// prevTimerを更新
	if ((m_prevTimer - m_countTimer) >= 1)
	{
		m_prevTimer = m_countTimer;
	}
}

// 描画処理
void Timer::Draw(TextGraph& text)
{
	char time[20];
	sprintf(time, "%d", m_countTimer);

	text.DrawTextMessage(1100, 20, "Time:");
	text.DrawTextMessage(1300, 20, time);
}

// タイマーを走らせる
const int& Timer::RunTimer(const int in_limit)
{
	int comfortTime = 1;      // 時間計算のゆとり

	// 制限時間を代入していなかった場合は代入し、開始時間もセット
	if (m_isInsert == false)
	{
		m_limitTime = in_limit + comfortTime;
		m_startTimer = GetNowCount();
		m_isInsert = true;
	}

	// カウンターにスタートしてから何秒経ったかを代入
	m_countTimer = (GetNowCount() / 1000) - (m_startTimer / 1000);

	// 制限時間からカウンター分を引いた値を返す
	return m_limitTime - m_countTimer;
}
