// タイマークラス

#pragma once
#include "DxLib.h"
#include "SceneInGame.h"

class Timer final
{
public:

	Timer();
	~Timer();

	void Initialize();

	void Delete();

	void Update();

	const int& GetTimer() const { return m_countTimer; }     // カウントタイマーのゲッター

private:

	int m_countTimer;

	int m_startTimer;

	int m_limitTime;

	static const int LIMIT_TIME;     // 1ゲームの制限時間
};