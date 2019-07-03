//-----------------------------------------------------------+
// ���C�����[�v
//      : ���C�����[�v
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#include "DxLib.h"
#include "GameSystem.h"
#include "Camera.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	// Dx���C�u��������������
	if (GameSystem::GetInstance().Initialize() == false)
	{
		GameSystem::GetInstance().ShutDown();
	}

	GameSystem::GetInstance().RunLoop();

	GameSystem::GetInstance().ShutDown();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}