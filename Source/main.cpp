//-----------------------------------------------------------+
// メインループ
//      : メインループ
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+

// インクルードファイル
#include "DxLib.h"
#include "GameSystem.h"

// ランチャー起動用関数(TGS2019展示用)
void LauncherBoot()
{
	Sleep(500);

	// プロセス起動準備
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.cb = sizeof(STARTUPINFO);

	CreateProcess("../../Launcher.exe", (LPSTR)"", NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, "../../", &si, &pi);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Dxライブラリ初期化処理
	if (GameSystem::GetInstance().Initialize() == false)
	{
		GameSystem::GetInstance().ShutDown();              // 初期化に失敗したら終了
	}

	// ゲームループ
	GameSystem::GetInstance().RunLoop();

	// ゲーム終了後、ランチャー起動
	LauncherBoot();

	return 0;				// ソフトの終了 
}