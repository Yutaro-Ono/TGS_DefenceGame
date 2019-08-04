#include "DirectorCountDown.h"

const int CountDown::MAX_START_TIME = 3;

CountDown::CountDown()
{
}

CountDown::~CountDown()
{
}

// 各種初期化処理
void CountDown::Initialize()
{
	m_prevTime = GetNowCount();
	m_nowTime = 0;

	// カウントダウンタイマー画像のロード
	// LoadDivGraph("Data/...", 3, 3, 0, )

	// タイマーのインスタンスを生成、初期化
	m_timer = new Timer();
	m_timer->Initialize();
}

void CountDown::Delete()
{
}

// ゲーム開始時のカウントダウン演出
void CountDown::StartCountDown()
{
	// カウントダウン処理
	m_timer->UpdateCountDown(MAX_START_TIME);

	// カウントダウンタイマーの取得
	m_nowTime = m_timer->GetTimer();

	// タイマーが0以下になったらディアクティベートする
	if (m_nowTime <= 0)
	{
		m_activate = false;
	}
}
