//-----------------------------------------------------------+
// メインループ
//      : メインループ
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#include "DxLib.h"
#include "GameSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Dxライブラリ初期化処理
	if (GameSystem::GetInstance().Initialize() == false)
	{
		GameSystem::GetInstance().ShutDown();              // 失敗したら終了
	}

	// ゲームループ
	GameSystem::GetInstance().RunLoop();

	return 0;				// ソフトの終了 
}