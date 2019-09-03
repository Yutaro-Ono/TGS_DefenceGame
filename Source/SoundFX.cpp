//-----------------------------------------------------------------------+
// サウンドエフェクト関連クラス                             
//                                              Last Update : 2019/08/24
//-----------------------------------------------------------------------+
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
}

// 初期化処理
void SoundFX::Initialize()
{
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
