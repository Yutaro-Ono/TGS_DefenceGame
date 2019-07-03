//-----------------------------------------------------------+
// メインループ
//      : メインループ
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#include "DxLib.h"
#include "GameSystem.h"
#include "Camera.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	// Dxライブラリ初期化処理
	if (GameSystem::GetInstance().Initialize() == false)
	{
		GameSystem::GetInstance().ShutDown();
	}

	GameSystem::GetInstance().RunLoop();

	GameSystem::GetInstance().ShutDown();

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}