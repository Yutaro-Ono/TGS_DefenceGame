//-----------------------------------------------------------------------+
// �G�t�F�N�g�N���X                         
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "Effect.h"

// �R���X�g���N�^
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

// �f�X�g���N�^
PlayEffect::~PlayEffect()
{
	// �����Ȃ�
}

// ����������
void PlayEffect::Initialize()
{
	m_playPos = VGet(0.0f, 0.0f, 0.0f);
	m_dotGraph = LoadGraph("Data/Effects/Effekseer1Dot.png", FALSE);
	m_playingEffect = -1;
}

// �������
void PlayEffect::Delete()
{
	if (GetNowPlaying() == 0)
	{
		StopEffect();
	}

	DeleteEffekseerEffect(m_effectHandle);
}

// �G�t�F�N�g�̍Đ����~�߂�
void PlayEffect::StopEffect()
{
	StopEffekseer3DEffect(m_playingEffect);
	m_playingEffect = -1;
}

// Effekseer3D�̕`��
void PlayEffect::PlayEffekseer(const VECTOR in_playPos)
{
	// printfDx(" (X���W : %f, Y���W : %f, Z���W : %f ", in_playPos.x, in_playPos.y, in_playPos.z);

	// printfDx("�G�t�F�N�g�Đ�");

	// �G�t�F�N�g�̍��W���X�V
	m_playPos = in_playPos;

	// �G�t�F�N�g�̕`��
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// �G�t�F�N�g���Đ�������W���w��
	SetPosPlayingEffekseer3DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

	// �摜��`�悵�Ă���(����)
	DrawGraph(0, 0, m_dotGraph, FALSE);
}

// Effekseer3D�̃T�C�Y���w�肵���Đ�
void PlayEffect::ChangeSizePlayEffekseer(const VECTOR in_playPos, const VECTOR in_size)
{
	// �G�t�F�N�g�̍��W�X�V
	m_playPos = in_playPos;

	// �G�t�F�N�g�̕`��
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// �G�t�F�N�g�̃T�C�Y��ݒ�
	SetScalePlayingEffekseer3DEffect(m_playingEffect, in_size.x, in_size.y, in_size.z);

	// �G�t�F�N�g���Đ�������W���w��
	SetPosPlayingEffekseer3DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

	// �摜��`�悵�Ă���
	DrawGraph(0, 0, m_dotGraph, FALSE);
}

void PlayEffect::PlayEffekseer2D(const VECTOR in_playPos)
{
	// �G�t�F�N�g�̍��W���X�V
	m_playPos = in_playPos;

	// �G�t�F�N�g�̕`��
	m_playingEffect = PlayEffekseer2DEffect(m_effectHandle);

	// �G�t�F�N�g���Đ�������W���w��
	SetPosPlayingEffekseer2DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

	// �摜��`�悵�Ă���(����)
	DrawGraph(0, 0, m_dotGraph, FALSE);
}
