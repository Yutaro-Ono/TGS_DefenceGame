#pragma once
#include "DxLib.h"
#include "PlayerManager.h"

class Score final
{
	

public:

	Score();
	~Score();

	void Initialize();

	void Update();

	void AddScore();

private:

	int m_score;              // スコア

	static const int SCORE_POINT;       // スコアポイント(加算用)
};