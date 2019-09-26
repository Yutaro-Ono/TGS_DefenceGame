//-----------------------------------------------------------------------+
// �^�C�}�[�N���X                        
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma warning(disable:4996)

// �C���N���[�h�t�@�C��
#include "Timer.h"
#include <iostream>

// �R���X�g���N�^
Timer::Timer()
	:m_countTimer(0)
	,m_startTimer(0)
	,m_prevTimer(0)
{
	// �����Ȃ�
}

// �f�X�g���N�^
Timer::~Timer()
{
	// �����Ȃ�
}

// ����������
void Timer::Initialize()
{
	m_isInsert = false;
	m_limitTime = 0;
	m_countTimer = 0;
	m_startTimer = GetNowCount();
	m_prevTimer = m_startTimer;
}

// �������
void Timer::Delete()
{
	// �����Ȃ�
}

// �J�E���g�A�b�v����
void Timer::CountUp()
{
	// ������
}

// �J�E���g�_�E�������̍X�V
void Timer::UpdateCountDown(const int in_maxTime)
{
	// �������Ԃ���͂������ǂ���
	bool in_Timer = false;

	// �������Ԃɓ��͂��Ă��Ȃ�������A�������Ԃɐݒ肵�����Ԃ����
	if (in_Timer == false)
	{
		m_limitTime = in_maxTime;
		in_Timer = true;
	}

	// �J�E���g�_�E���^�C�}�[���擾
	m_countTimer = m_limitTime - ((GetNowCount() - m_startTimer) / 1000);

	// prevTimer���X�V
	if ((m_prevTimer - m_countTimer) >= 1)
	{
		m_prevTimer = m_countTimer;
	}
}

// �`�揈��
void Timer::Draw(TextGraph& text)
{
	char time[20];
	sprintf(time, "%d", m_countTimer);

	text.DrawTextMessage(1100, 20, "Time:");
	text.DrawTextMessage(1300, 20, time);
}

// �^�C�}�[�𑖂点��
const int& Timer::RunTimer(const int in_limit)
{
	int comfortTime = 1;      // ���Ԍv�Z�̂�Ƃ�

	// �������Ԃ������Ă��Ȃ������ꍇ�͑�����A�J�n���Ԃ��Z�b�g
	if (m_isInsert == false)
	{
		m_limitTime = in_limit + comfortTime;
		m_startTimer = GetNowCount();
		m_isInsert = true;
	}

	// �J�E���^�[�ɃX�^�[�g���Ă��牽�b�o����������
	m_countTimer = (GetNowCount() / 1000) - (m_startTimer / 1000);

	// �������Ԃ���J�E���^�[�����������l��Ԃ�
	return m_limitTime - m_countTimer;
}
