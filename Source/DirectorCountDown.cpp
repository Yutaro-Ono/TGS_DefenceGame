#include "DirectorCountDown.h"

const int CountDown::MAX_START_TIME = 3;

CountDown::CountDown()
{
}

CountDown::~CountDown()
{
}

// �e�평��������
void CountDown::Initialize()
{
	m_prevTime = GetNowCount();
	m_nowTime = 0;

	// �J�E���g�_�E���^�C�}�[�摜�̃��[�h
	// LoadDivGraph("Data/...", 3, 3, 0, )

	// �^�C�}�[�̃C���X�^���X�𐶐��A������
	m_timer = new Timer();
	m_timer->Initialize();
}

void CountDown::Delete()
{
}

// �Q�[���J�n���̃J�E���g�_�E�����o
void CountDown::StartCountDown()
{
	// �J�E���g�_�E������
	m_timer->UpdateCountDown(MAX_START_TIME);

	// �J�E���g�_�E���^�C�}�[�̎擾
	m_nowTime = m_timer->GetTimer();

	// �^�C�}�[��0�ȉ��ɂȂ�����f�B�A�N�e�B�x�[�g����
	if (m_nowTime <= 0)
	{
		m_activate = false;
	}
}
