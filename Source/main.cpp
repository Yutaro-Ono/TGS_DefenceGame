//-----------------------------------------------------------+
// ���C�����[�v
//      : ���C�����[�v
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "GameSystem.h"

// �����`���[�N���p�֐�(TGS2019�W���p)
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
		GameSystem::GetInstance().ShutDown();              // �������Ɏ��s������I��
	}

	// �Q�[�����[�v
	GameSystem::GetInstance().RunLoop();

	// �Q�[���I����A�����`���[�N��
	LauncherBoot();

	return 0;				// �\�t�g�̏I�� 
}