//-----------------------------------------------------------------------+
// タイトルシーン                  
//                                              Last Update : 2019/07/10
//-----------------------------------------------------------------------+

#include "SceneTitle.h"
#include "Input.h"
#include "GameSystem.h"

SceneTitle::SceneTitle()
	:toNext(0)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Initialize()
{
	// タイトルロゴ画像をロード、サイズ取得
	m_titleLogoGraph = LoadGraph("Data/Interface/Title_Logo.png");
	GetGraphSize(m_titleLogoGraph, &m_titleLogoW, &m_titleLogoH);
}

void SceneTitle::Delete()
{
}

void SceneTitle::Update(Input & input, Camera & camera, float deltaTime)
{

	input.KeyChecker();

	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		toNext = 2;
	}
	
	
	Draw();
}

void SceneTitle::Draw()
{
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 50, "SPACEキーでスタート", GetColor(255, 255, 255));
}
