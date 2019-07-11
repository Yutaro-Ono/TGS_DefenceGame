//-----------------------------------------------------------------------+
// リザルトシーン                         
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+
#include "SceneResult.h"

SceneResult::SceneResult()
	:toNext(3)
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

void SceneResult::Update(Input & input, Camera & camera, float deltaTime)
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		toNext = 0;
	}
}

void SceneResult::Draw()
{
	DrawFormatString(GAME_INSTANCE.GetScreenWidth(), GAME_INSTANCE.GetScreenHeight(), GetColor(255, 255, 255), "生き残れた");

}
