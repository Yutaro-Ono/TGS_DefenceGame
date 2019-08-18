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

	void PlayDamageEffect(const VECTOR in_playPos);

	

private:

	int m_damageEffectHandle;        // ��_���[�W�G�t�F�N�g�̃n���h��
	int m_playingDamageEffect;


};