#include "Effect.h"

PlayEffect::PlayEffect(const char* sourceEffectHandle)
	:m_damageEffectHandle(-1)
{
	// モデルのロード
	m_damageEffectHandle = LoadEffekseerEffect(sourceEffectHandle);
	if (m_damageEffectHandle == -1)
	{
		printfDx("エフェクト読み込み失敗");
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

// 被ダメージエフェクトの描画
void PlayEffect::PlayDamageEffect(const VECTOR in_playPos)
{
	// エフェクトの描画
	m_playingDamageEffect = PlayEffekseer3DEffect(m_damageEffectHandle);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer3DEffect(m_damageEffectHandle, in_playPos.x, in_playPos.y, in_playPos.z);
}
