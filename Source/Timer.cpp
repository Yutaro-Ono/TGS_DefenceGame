//-----------------------------------------------------------------------+
// �^�C�}�[�N���X                        
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Timer.h"
#include <iostream>

const int Timer::LIMIT_TIME = 60;

Timer::Timer()
	:m_countTimer(0)
	,m_startTimer(0)
	,m_limitTime(LIMIT_TIME)
	,m_prevTimer(0)
{

}

Timer::~Timer()
{

}

void Timer::Initialize()
{
	m_countTimer = 0;
	m_startTimer = GetNowCount() / 1000;
	m_prevTimer = m_startTimer;
}

void Timer::Delete()
{
}

void Timer::Update()
{
	// �J�E���g�_�E���^�C�}�[���擾
	m_countTimer = m_limitTime - ((GetNowCount() / 1000) - m_startTimer);

	// prevTimer���X�V
	if ((m_prevTimer - m_countTimer) >= 1)
	{
		m_prevTimer = m_countTimer;
	}
}

void Timer::Draw()
{
	DrawFormatString(1100, 0, GetColor(255, 255, 255), "�������ԁF%d", m_countTimer);
}
