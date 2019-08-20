#include "Effect.h"

PlayEffect::PlayEffect(const char* sourceEffectHandle)
	:m_effectHandle(-1)
{
	// モデルのロード
	m_effectHandle = LoadEffekseerEffect(sourceEffectHandle);
	if (m_effectHandle == -1)
	{
		printfDx("エフェクト読み込み失敗");
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

// 被ダメージエフェクトの描画
void PlayEffect::PlayEffekseer(const VECTOR in_playPos)
{
	//printfDx(" (X座標 : %f, Y座標 : %f, Z座標 : %f ", in_playPos.x, in_playPos.y, in_playPos.z);

	// エフェクトの描画
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer3DEffect(m_effectHandle, in_playPos.x, in_playPos.y, in_playPos.z);
}
