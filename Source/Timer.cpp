//-----------------------------------------------------------------------+
// �^�C�}�[�N���X                        
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
	// ���쐬
}

void Timer::UpdateCountDown(const int in_maxTime)
{
	// �������Ԃ���͂������ǂ���
	bool in_Timer = false;

	// �������Ԃɓ��͂��Ă��Ȃ�������A�������Ԃɐݒ肵�����Ԃ����
	if (in_Timer == 0)
	{
		m_limitTime = in_maxTime;
		in_Timer = true;
	}

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
