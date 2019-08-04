#include "DirectionCountDown.h"

CountDown::CountDown()
{
}

CountDown::~CountDown()
{
}

// Šeí‰Šú‰»ˆ—
void CountDown::Initialize()
{
	m_prevTick = GetNowCount();
	m_nowTick = 0;
}

void CountDown::StartCountDown()
{
	m_nowTick = GetNowCount();
}
