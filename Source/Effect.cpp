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
	m_playPos = VGet(0.0f, 0.0f, 0.0f);
	m_dotGraph = LoadGraph("Data/Effects/Effekseer1Dot.png", FALSE);
	m_playingEffect = -1;
}

void PlayEffect::Delete()
{
	DeleteEffekseerEffect(m_effectHandle);
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

	m_playPos = in_playPos;

	// エフェクトの描画
	m_playingEffect = PlayEffekseer3DEffect(m_effectHandle);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer3DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

	DrawGraph(0, 0, m_dotGraph, FALSE);

}

void PlayEffect::PlayEffekseer2D(const VECTOR in_playPos)
{
	m_playPos = in_playPos;

	// エフェクトの描画
	m_playingEffect = PlayEffekseer2DEffect(m_effectHandle);

	// エフェクトを再生する座標を指定
	SetPosPlayingEffekseer2DEffect(m_playingEffect, m_playPos.x, m_playPos.y, m_playPos.z);

	DrawGraph(0, 0, m_dotGraph, FALSE);
}
