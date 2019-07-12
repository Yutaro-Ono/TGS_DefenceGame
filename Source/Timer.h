// タイマークラス

#pragma once
#include "DxLib.h"
#include "SceneInGame.h"

class Timer final
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

private:

	Timer();

	int m_countTimer;

	int m_startTimer;

	int m_limitTime;

	static const int LIMIT_TIME;     // 1ゲームの制限時間
};

#define TIMER_INSTANCE Timer::GetInstatnce()