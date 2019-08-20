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
	// 2D��Effekseer�Đ�
	void PlayEffekseer2D(const VECTOR in_playPos);

	void StopEffect();

	const int& GetNowPlaying()const { return IsEffekseer3DEffectPlaying(m_playingEffect); }    // �G�t�F�N�g���Đ������ǂ���(0:�Đ���  1:�Đ�����Ă��Ȃ�)

	// �Đ�����G�t�F�N�g�̊g�嗦��ύX����
	void SetEffectScale(const float in_sizeX, const float in_sizeY, const float in_sizeZ) { SetScalePlayingEffekseer3DEffect(m_playingEffect, in_sizeX, in_sizeY, in_sizeZ); }

private:

	VECTOR m_playPos;          // �G�t�F�N�g�̍��W

	int m_effectHandle;        // ��_���[�W�G�t�F�N�g�̃n���h��
	int m_playingEffect;

	int m_dotGraph;            // �G�t�F�N�g�Đ��ɕK�v�ȕ`��p�摜


};