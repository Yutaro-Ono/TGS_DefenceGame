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
}

// 描画関連処理
void CountDown::Draw()
{
	// カウントダウンタイマーの描画
	DrawGraph(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, m_counterGraph[-m_nowTime], TRUE);
}

// ゲーム開始時のカウントダウン演出
bool CountDown::StartCountDown()
{
	// カウントダウン処理
	m_timer->UpdateCountDown(MAX_START_TIME);

	// カウントダウンタイマーの取得
	m_nowTime = m_timer->GetTimer();

	// 描画
	Draw();

	// タイマーが0以下になったらtrueを返す
	if (m_nowTime >= 0)
	{
		return true;
	}

	return false;
}
