#include "Effect.h"

PlayEffect::PlayEffect(const char* sourceEffectHandle)
	:m_damageEffectHandle(-1)
{
	// ���f���̃��[�h
	m_damageEffectHandle = LoadEffekseerEffect(sourceEffectHandle);
	if (m_damageEffectHandle == -1)
	{
		printfDx("�G�t�F�N�g�ǂݍ��ݎ��s");
	}
}

PlayEffect::~PlayEffect()
{
}

void PlayEffect::Initialize()
{
	m_playingDamageEffect = -1;
}

void PlayEffect::Delete()
{
}

// ��_���[�W�G�t�F�N�g�̕`��
void PlayEffect::PlayDamageEffect(const VECTOR in_playPos)
{
	// �G�t�F�N�g�̕`��
	m_playingDamageEffect = PlayEffekseer3DEffect(m_damageEffectHandle);

	// �G�t�F�N�g���Đ�������W���w��
	SetPosPlayingEffekseer3DEffect(m_damageEffectHandle, in_playPos.x, in_playPos.y, in_playPos.z);
}
