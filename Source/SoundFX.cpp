//-----------------------------------------------------------------------+
// サウンドエフェクト関連クラス                             
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "SoundFX.h"

// コンストラクタ
SoundFX::SoundFX(const char* in_fileName)
	:m_sourceSoundHandle(-1)
{
	m_sourceSoundHandle = LoadSoundMem(in_fileName);

	//if (m_sourceSoundHandle == -1)
	//{
	//	printfDx("音楽データ読み込み失敗");
	//}
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
