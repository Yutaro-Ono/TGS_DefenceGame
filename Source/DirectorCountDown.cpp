#include "DirectorCountDown.h"

const int CountDown::MAX_START_TIME = 3;

// コンストラクタ
CountDown::CountDown()
{
}

// デストラクタ
CountDown::~CountDown()
{
}

// 各種初期化処理
void CountDown::Initialize()
{
	m_prevTime = GetNowCount();
	m_nowTime = 0;

	// カウントダウンタイマー画像のロード
	LoadDivGraph("Data/Interface/In_GameUI/Timer/CountDown_900x300.png", 3, 3, 1, 300, 300, m_counterGraph, TRUE);

	// タイマーのインスタンスを生成、初期化
	m_timer = new Timer();
	m_timer->Initialize();
}

// 各種解放処理
void CountDown::Delete()
{
	m_timer->Delete();
	delete (m_timer);
}

// 描画関連処理
void CountDown::Draw(TextGraph& text)
{
	//const char* timeText;

	//timeText = (char*)m_nowTime;

	//text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2 - 64, GAME_INSTANCE.GetScreenHeight() / 2 - 64, timeText);

	// カウントダウンタイマーの描画
	DrawGraph(GAME_INSTANCE.GetScreenWidth() / 2 - 150, GAME_INSTANCE.GetScreenHeight() / 2 - 300, m_counterGraph[GetTimeGraphNum(m_nowTime)], TRUE);
}

// ゲーム開始時のカウントダウン演出
bool CountDown::StartCountDown()
{
	// カウントダウン処理
	m_nowTime = m_timer->RunTimer(MAX_START_TIME);

	// 描画
	// Draw();

	// タイマーが0以下になったらtrueを返す
	if (m_nowTime <= 0)
	{
		return true;
	}

	return false;
}

// カウンターに基づく画像参照番号のゲッター
const int & CountDown::GetTimeGraphNum(const int in_nowTime) const
{
	// 3秒
	if (m_nowTime == 3)
	{
		return 2;
	}

	// 2秒
	if (m_nowTime == 2)
	{
		return 1;
	}

	// 1秒
	if (m_nowTime == 1)
	{
		return 0;
	}

	return -1;
}
