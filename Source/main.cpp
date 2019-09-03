//-----------------------------------------------------------+
// ���C�����[�v
//      : ���C�����[�v
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#include "DxLib.h"
#include "GameSystem.h"

// �����`���[�N���p�֐�
void LauncherBoot()
{
	Sleep(500);

	// �v���Z�X�N������
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.cb = sizeof(STARTUPINFO);

	CreateProcess("../../Launcher.exe", (LPSTR)"", NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, "../../", &si, &pi);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Dx���C�u��������������
	if (GameSystem::GetInstance().Initialize() == false)
	{
		GameSystem::GetInstance().ShutDown();              // ���s������I��
	}

	// �Q�[�����[�v
	GameSystem::GetInstance().RunLoop();

	// �Q�[���I����A�����`���[�N��
	LauncherBoot();

	return 0;				// �\�t�g�̏I�� 
}