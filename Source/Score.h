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

	int m_score;              // �X�R�A

	static const int SCORE_POINT;       // �X�R�A�|�C���g(���Z�p)
};