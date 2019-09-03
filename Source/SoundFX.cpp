//-----------------------------------------------------------------------+
// �T�E���h�G�t�F�N�g�֘A�N���X                             
//                                              Last Update : 2019/08/24
//-----------------------------------------------------------------------+
#include "SoundFX.h"

// �R���X�g���N�^
SoundFX::SoundFX(const char* in_fileName)
	:m_sourceSoundHandle(-1)
{
	m_sourceSoundHandle = LoadSoundMem(in_fileName);
	if (m_sourceSoundHandle == -1)
	{
		printfDx("���y�f�[�^�ǂݍ��ݎ��s");
	}
}

// �f�X�g���N�^
SoundFX::~SoundFX()
{
}

// ����������
void SoundFX::Initialize()
{
}

// �������
void SoundFX::Delete()
{
	DeleteSoundMem(m_sourceSoundHandle);
}

// �T�E���h�Đ��֐�
void SoundFX::PlaySoundFx()
{
	// ���łɍĐ����Ă��Ȃ����Ƃ��m�F���čĐ�
	if (CheckSoundMem(m_sourceSoundHandle) == 0)
	{
		PlaySoundMem(m_sourceSoundHandle, DX_PLAYTYPE_BACK, FALSE);
	}
	
}

// �T�E���h�̃��[�v�Đ�
void SoundFX::PlayLoopSoundFx()
{
	PlaySoundMem(m_sourceSoundHandle, DX_PLAYTYPE_LOOP, FALSE);
}

// �Đ����̃T�E���h��~
void SoundFX::StopSoundFx()
{
	StopSoundMem(m_sourceSoundHandle);
}


bool SoundFX::ScanNowPlaySound()
{
	// ���݉��y�t�@�C�����Đ������ǂ����𒲂ׁA�Đ����Ă�����true��Ԃ��A�Đ����Ă��Ȃ�������false��Ԃ�
	if (CheckSoundMem(m_sourceSoundHandle) == 0)
	{
		return true;
	}

	else
	{
		return false;
	}


	return false;
}
