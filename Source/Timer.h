// タイマークラス

#pragma once
#include "DxLib.h"
#include "SceneInGame.h"

class Timer
{
public:

	// シングルトン
	static Timer& GetInstatnce()
	{
		static Timer timer;
		return timer;
	}

	~Timer();                 // デストラクタ

	void Initialize();        // タイマーの初期化

	void Delete();            // タイマーの削除

	void Update();            // タイマーの計測

	void Draw();              // タイマーの描画

	const int& GetTimer() const { return m_countTimer; }     // カウントタイマーのゲッター

	const int& GetPrevTimer() const { return m_prevTimer; }  // 一秒前のタイマーゲッター

private:

	Timer();

	int m_countTimer;       // カウントダウン用タイマー

	int m_startTimer;       // スタート時タイマー

	int m_limitTime;        // 制限時間

	int m_prevTimer;         // 前のタイマー

	

	static const int LIMIT_TIME;     // 1ゲームの制限時間
};

#define TIMER_INSTANCE Timer::GetInstatnce()