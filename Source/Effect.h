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

	const int& GetNowPlaying()const { return IsEffekseer3DEffectPlaying(m_effectHandle); }    // エフェクトが再生中かどうか(0:再生中  1:再生されていない)

private:

	int m_effectHandle;        // 被ダメージエフェクトのハンドル
	int m_playingEffect;


};