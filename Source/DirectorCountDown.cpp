#include "DirectorCountDown.h"

const int CountDown::MAX_START_TIME = 3;

// �R���X�g���N�^
CountDown::CountDown()
{
}

// �f�X�g���N�^
CountDown::~CountDown()
{
}

// �e�평��������
void CountDown::Initialize()
{
	m_prevTime = GetNowCount();
	m_nowTime = 0;

	// �J�E���g�_�E���^�C�}�[�摜�̃��[�h
	LoadDivGraph("Data/Interface/In_GameUI/Timer/CountDown_900x300.png", 3, 3, 1, 300, 300, m_counterGraph, TRUE);

	// �^�C�}�[�̃C���X�^���X�𐶐��A������
	m_timer = new Timer();
	m_timer->Initialize();
}

// �e��������
void CountDown::Delete()
{
}

// �`��֘A����
void CountDown::Draw()
{
	// �J�E���g�_�E���^�C�}�[�̕`��
	DrawGraph(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, m_counterGraph[-m_nowTime], TRUE);
}

// �Q�[���J�n���̃J�E���g�_�E�����o
bool CountDown::StartCountDown()
{
	// �J�E���g�_�E������
	m_timer->UpdateCountDown(MAX_START_TIME);

	// �J�E���g�_�E���^�C�}�[�̎擾
	m_nowTime = m_timer->GetTimer();

	// �`��
	Draw();

	// �^�C�}�[��0�ȉ��ɂȂ�����true��Ԃ�
	if (m_nowTime >= 0)
	{
		return true;
	}

	return false;
}
