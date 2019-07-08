//-----------------------------------------------------------+
// �Q�[���V�X�e���N���X
//      : �S�Ă̏������s��
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Math.h"
#include "ModelLoader.h"
#include "Input.h"
#include "Camera.h"
#include "ObjectBase.h"
#include "ObjectManager.h"
#include "PlayerManager.h"
#include "SceneBase.h"
#include "SceneInGame.h"
#include <vector>

#pragma comment(lib, "winmm.lib")

class Input;
class Camera;

class GameSystem
{
public:

	enum SCENE_PHASE
	{
		START = 0,
		TUTORIAL,
		GAME,
		GAME_END,
	};

	static GameSystem& GetInstance()
	{
		static GameSystem system;
		return system;
	}

	~GameSystem();            // �f�X�g���N�^

	bool Initialize();        // �e�평��������

	void RunLoop();           // �Q�[�����[�v

	void ShutDown();          // �I������

	// ��ʐݒ��getter
	const int& GetScreenWidth()const { return m_screenWidth; }
	const int& GetScreenHeight()const { return m_screenHeight; }
	// ��ʐݒ��setter
	void SetScreen(const int& scrWidth, const int& scrHeight, const bool& fullScreen);

private:
	GameSystem();       // �R���X�g���N�^   



	int Update();       // Scene�J�ڍX�V�p

	void UpdateMove();       // �ړ��֘A�̍X�V

	void UpdateDraw();       // �`��֘A�̍X�V

	bool ProgramLoop();    // Windows�v���Z�X�̃G���[��Ԃ�

	SceneBase* m_scene;                  // �C���Q�[���V�[��

	Input* m_input;                        // ���͊֘A

	Camera* m_camera;                      // �J����

	// �E�B���h�E(Width : ��, Height : ����)
	int m_screenWidth;
	int m_screenHeight;

	bool m_fullScreen;         // �t���X�N���[�����ǂ���
	bool m_isGameQuit;         // �Q�[�����I�����邩�ǂ���

	float m_deltaTime;         // 1�t���[���̍X�V����
};

 //#define GAME_INSTANCE GameSystem::GetInstance()