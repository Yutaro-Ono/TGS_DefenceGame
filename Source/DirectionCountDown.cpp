#include "DirectionCountDown.h"

CountDown::CountDown()
{
}

CountDown::~CountDown()
{
}

// 各種初期化処理
void CountDown::Initialize()
{
	m_prevTick = GetNowCount();
	m_nowTick = 0;
}

void CountDown::StartCountDown()
{
	m_nowTick = GetNowCount();
}
