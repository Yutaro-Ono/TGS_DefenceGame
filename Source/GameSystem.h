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
#include "SceneTitle.h"
#include "SceneInGame.h"
#include "SceneResult.h"
#include <vector>

#pragma comment(lib, "winmm.lib")

class Input;
class Camera;
class SceneInGame;
class SceneResult;

class GameSystem
{
public:

	// �Q�[���V�[�������t�F�[�Y�Ƃ��Ē�`
	enum SCENE_PHASE
	{
		INIT = 0,
		START,
		TUTORIAL,
		GAME,
		GAME_END,
		SHUT_DOWN,
	};

	// �V���O���g��
	static GameSystem& GetInstance()
	{
		static GameSystem system;
		return system;
	}
	
	~GameSystem();                               // �f�X�g���N�^

	bool Initialize();                           // �e�평��������

	void Create();                               // �C���X�^���X�Ȃǂ̐�������

	void Delete();                               // �폜�֐�

	void RunLoop();                              // �Q�[�����[�v

	void ShutDown();                             // �I������

	//--------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------+
	// ��ʐݒ�(�c��)�̃Q�b�^�[
	const int& GetScreenWidth()const { return m_screenWidth; }
	const int& GetScreenHeight()const { return m_screenHeight; }
	// ��ʐݒ�̃Z�b�^�[
	void SetScreen(const int& scrWidth, const int& scrHeight, const bool& fullScreen);

private:
	GameSystem();                                // �R���X�g���N�^

	int Update();                                // Scene�J�ڍX�V�p

	void UpdateMove();                           // �ړ��֘A�̍X�V

	void UpdateDraw();                           // �`��֘A�̍X�V

	bool ProgramLoop();                          // Windows�v���Z�X�̃G���[��Ԃ�


	SceneTitle* m_titleScene;                    // �^�C�g���V�[��
	SceneInGame* m_inGameScene;                  // �C���Q�[���V�[��
	SceneResult* m_resultScene;                  // ���U���g�V�[��
	Camera* m_camera;                            // �J����
	Input* m_input;                              // ����

	// �E�B���h�E(Width : ��, Height : ����)
	int m_screenWidth;
	int m_screenHeight;

	bool m_fullScreen;                           // �t���X�N���[�����ǂ���
	bool m_isGameQuit;                           // �Q�[�����I�����邩�ǂ���

	int sceneNum;                                // �ǂ̃V�[����

	float m_deltaTime;                           // 1�t���[���̍X�V����
};

 #define GAME_INSTANCE GameSystem::GetInstance()