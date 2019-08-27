//-----------------------------------------------------------+
// ���C�����[�v
//      : ���C�����[�v
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#include "DxLib.h"
#include "GameSystem.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// Dx���C�u��������������
	if (GameSystem::GetInstance().Initialize() == false)
	{
		GameSystem::GetInstance().ShutDown();              // ���s������I��
	}

	// �Q�[�����[�v
	GameSystem::GetInstance().RunLoop();

	return 0;				// �\�t�g�̏I�� 
}