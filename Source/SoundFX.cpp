//-----------------------------------------------------------------------+
// サウンドエフェクト関連クラス                             
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "SoundFX.h"

// コンストラクタ
SoundFX::SoundFX(const char* in_fileName)
	:m_sourceSoundHandle(-1)
{
	m_sourceSoundHandle = LoadSoundMem(in_fileName);
	if (m_sourceSoundHandle == -1)
	{
		printfDx("音楽データ読み込み失敗");
	}
}

// デストラクタ
SoundFX::~SoundFX()
{
	// 処理なし
}

// 初期化処理
void SoundFX::Initialize()
{
	// 処理なし
}

// 解放処理
void SoundFX::Delete()
{
	DeleteSoundMem(m_sourceSoundHandle);
}

// サウンド再生関数
void SoundFX::PlaySoundFx()
{
	// すでに再生していないことを確認して再生
	if (CheckSoundMem(m_sourceSoundHandle) == 0)
	{
		PlaySoundMem(m_sourceSoundHandle, DX_PLAYTYPE_BACK, FALSE);
	}
}

// サウンドのループ再生
void SoundFX::PlayLoopSoundFx()
{
	PlaySoundMem(m_sourceSoundHandle, DX_PLAYTYPE_LOOP, FALSE);
}

// 再生中のサウンド停止
void SoundFX::StopSoundFx()
{
	StopSoundMem(m_sourceSoundHandle);
}

// 現在音楽が再生されているかどうかを検出
bool SoundFX::ScanNowPlaySound()
{
	// 現在音楽ファイルが再生中かどうかを調べ、再生していたらtrueを返し、再生していなかったらfalseを返す
	if (CheckSoundMem(m_sourceSoundHandle) == 0)
	{
		return true;
	}

	else
	{
		return false;
	}

	return false;
}
