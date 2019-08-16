//-----------------------------------------------------------------------+
// リザルトシーン                         
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+
#include "SceneResult.h"

SceneResult::SceneResult()
	:toNext(4)
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Initialize()
{
}

void SceneResult::Delete()
{
}

void SceneResult::Update(Camera & camera, Input& input, float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		toNext = 5;
	}
}

void SceneResult::Draw()
{
	if (m_clear == true)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "生き残れた");
	}
	if (m_clear == false)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "生き残れなかった");
	}

	
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 50, GetColor(255, 255, 255), "ENTERキーでリトライ");
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 100, GetColor(255, 255, 255), "ESCAPEキーで終了");
}
