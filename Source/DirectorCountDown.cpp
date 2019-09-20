//--------------------------------------------------------------+
// �J�E���g�_�E���n�̉��o�����N���X
//                                             2019 Yutaro Ono.
//--------------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "DirectorCountDown.h"

const int CountDown::MAX_START_TIME = 3;

// �R���X�g���N�^
CountDown::CountDown()
{
	// �����Ȃ�
}

// �f�X�g���N�^
CountDown::~CountDown()
{
	// �����Ȃ�
}

// �e�평��������
void CountDown::Initialize()
{
	m_prevTime = 0;
	m_nowTime = 0;

	m_playSE = false;

	// �J�E���g�_�E���^�C�}�[�摜�̃��[�h
	LoadDivGraph("Data/Interface/In_GameUI/Timer/CountDown_900x300.png", 3, 3, 1, 300, 300, m_counterGraph, TRUE);

	// �^�C�}�[�̃C���X�^���X�𐶐��A������
	m_timer = new Timer();
	m_timer->Initialize();
	// �T�E���h
	m_sound = new SoundFX("Data/Music/SE/System/Count/se_maoudamashii_system27.mp3");
	m_sound->Initialize();
}

// �e��������
void CountDown::Delete()
{
	m_timer->Delete();
	m_sound->Delete();
	delete (m_timer);
	delete (m_sound);
}

// �`��֘A����
void CountDown::Draw(TextGraph& text)
{
	// �J�E���g�_�E���^�C�}�[�̕`��
	DrawGraph(GAME_INSTANCE.GetScreenWidth() / 2 - 150, GAME_INSTANCE.GetScreenHeight() / 2 - 300, m_counterGraph[GetTimeGraphNum(m_nowTime)], TRUE);
}

// �Q�[���J�n���̃J�E���g�_�E�����o
bool CountDown::StartCountDown()
{

	// �J�E���g�_�E������
	m_nowTime = m_timer->RunTimer(MAX_START_TIME);

	// �^�C�}�[���X�V���ꂽ��SE���Đ�����(1�J�E���g��1��SE��炷)
	if (m_prevTime != m_nowTime  && m_nowTime != 0)
	{
		m_sound->PlaySoundFx();
		m_prevTime = m_nowTime;
	}

	// �^�C�}�[��0�ȉ��ɂȂ�����true��Ԃ�
	if (m_nowTime <= 0)
	{
		return true;
	}

	return false;
}

// �J�E���^�[�Ɋ�Â��摜�Q�Ɣԍ��̃Q�b�^�[
const int & CountDown::GetTimeGraphNum(const int in_nowTime) const
{
	// 3�b
	if (m_nowTime == 3)
	{
		return 2;
	}

	// 2�b
	if (m_nowTime == 2)
	{
		return 1;
	}

	// 1�b
	if (m_nowTime == 1)
	{
		return 0;
	}

	return -1;
}
