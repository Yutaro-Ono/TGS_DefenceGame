//-----------------------------------------------------------------------+
// タイトルシーン                  
//                                              Last Update : 2019/07/10
//-----------------------------------------------------------------------+

#include "SceneTitle.h"
#include "Input.h"


SceneTitle::SceneTitle()
	:toNext(0)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Initialize()
{
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
	DrawString(500, 300, "SPACE HAMSTER\nSPACEを押してください", GetColor(255, 255, 255));
}
