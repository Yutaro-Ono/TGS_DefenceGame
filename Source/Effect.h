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

	int m_damageEffectHandle;        // 被ダメージエフェクトのハンドル
	int m_playingDamageEffect;


};