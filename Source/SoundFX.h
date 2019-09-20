//-----------------------------------------------------------+
// サウンドクラス
//      : サウンド関連のロード、再生を一元管理
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"



class SoundFX final
{
public:

	SoundFX(const char* in_fileName);        // コンストラクタ
	~SoundFX();                              // デストラクタ

	void Initialize();                       // 初期化処理

	void Delete();                           // 解放処理

	void PlaySoundFx();                      // サウンド再生関数

	void PlayLoopSoundFx();                  // サウンドのループ再生

	void StopSoundFx();                      // 再生中のサウンド停止

	// 今音楽ファイルを再生しているかどうか？
	bool ScanNowPlaySound();

private:

	int m_sourceSoundHandle;                 // 音楽ファイルのハンドル
	
};