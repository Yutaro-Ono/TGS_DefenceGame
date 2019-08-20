#include "Effect.h"

PlayEffect::PlayEffect(const char* sourceEffectHandle)
	:m_effectHandle(-1)
{
	// ���f���̃��[�h
	m_effectHandle = LoadEffekseerEffect(sourceEffectHandle);
	if (m_effectHandle == -1)
	{
		printfDx("�G�t�F�N�g�ǂݍ��ݎ��s");
	}
}

PlayEffect::~PlayEffect()
{
}

void PlayEffect::Initialize()
{
	m_playingEffect = -1;
}

void PlayEffect::Delete()
{
}

void PlayEffect::StopEffect()
{
	StopEffekseer3DEffect(m_playingEffect);
	m_playingEffect = -1;
}

// ��_���[�W�G�t�F�N�g�̕`��
void PlayEffect::PlayEffekseer(const VECTOR in_playPos)
{
	//printfDx(" (X���W : %f, Y���W : %f, Z���W : %f ", in_playPos.x, in_playPos.y, in_playPos.z);

	// �G�t�F�N�g�̕`��
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// �G�t�F�N�g���Đ�������W���w��
	SetPosPlayingEffekseer3DEffect(m_effectHandle, in_playPos.x, in_playPos.y, in_playPos.z);
}
