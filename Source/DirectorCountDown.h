//--------------------------------------------------------------+
// カウントダウン系の演出総合クラス
//      : ゲーム開始時、インターバル時のカウントダウン演出処理
//                                             2019 Yutaro Ono.
//--------------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "DirectorBase.h"
#include "Timer.h"
#include "GameSystem.h"
#include "TextGraph.h"
#include "SoundFX.h"

// クラス前方宣言
class Timer;
class TextGraph;
class SoundFX;

class CountDown : public DirectorBase
{

public:

	CountDown();                         // コンストラクタ
	~CountDown();                        // デストラクタ

	void Initialize() override;          // 各種初期化処理

	void Delete() override;              // 各種解放処理

	void Draw(TextGraph& text);          // 描画処理

	bool StartCountDown();               // ゲーム開始時のカウントダウン演出

	//--------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------+
	// タイマーの値に基づく画像番号の取得
	const int& GetTimeGraphNum(const int in_nowTime) const;


private:

	int m_prevTime;                                                // 前回の更新時間
	int m_nowTime;                                                 // 現在の更新時間

	int m_counterGraph[3];                                         // カウントダウンの描画用グラフィックハンドル

	bool m_playSE;                                                 // SE再生のフラグ

	Timer* m_timer;                                                // タイマークラス
	SoundFX* m_sound;                                              // サウンド

	static const int MAX_START_TIME;                               // 開始時の最大カウントダウン時間

};