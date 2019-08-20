#pragma once
#include "DxLib.h"
#include "EffekseerForDXLib.h"


class PlayEffect
{
public:

	PlayEffect(const char* sourceEffectHandle);
	~PlayEffect();

	void Initialize();

	void Delete();

	void PlayEffekseer(const VECTOR in_playPos);

	void StopEffect();

	const int& GetNowPlaying()const { return IsEffekseer3DEffectPlaying(m_effectHandle); }    // �G�t�F�N�g���Đ������ǂ���(0:�Đ���  1:�Đ�����Ă��Ȃ�)

private:

	int m_effectHandle;        // ��_���[�W�G�t�F�N�g�̃n���h��
	int m_playingEffect;


};