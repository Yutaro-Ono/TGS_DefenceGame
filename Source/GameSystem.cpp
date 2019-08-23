//-----------------------------------------------------------------------+
// �Q�[���V�X�e���N���X                         
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include <iostream>
#include <Windows.h>
#include "EffekseerForDXLib.h"
#include "Camera.h"
#include "GameSystem.h"
#include "SceneTitle.h"
#include "SceneInGame.h"

// �R���X�g���N�^
GameSystem::GameSystem()
	:m_screenWidth(0)
	,m_screenHeight(0)
	,m_fullScreen(false)
	,sceneNum(1)
	,m_deltaTime(0.0f)
{
	m_isGameQuit = false;
}

// �f�X�g���N�^
GameSystem::~GameSystem()
{
	// �����Ȃ�
}

// �e�평����
bool GameSystem::Initialize()
{
	// ��ʂ�ݒ�
	SetScreen(1920, 1080, true);

	// �S��ʕ\���t���O���I�t��������E�B���h�E���[�h�ɂ���
	if (m_fullScreen)
	{
		ChangeWindowMode(TRUE);
	}

	// ��ʐݒ���X�V
	SetGraphMode(m_screenWidth, m_screenHeight, 32, 60);

	SetFontSize(50);             // �g�p����t�H���g�T�C�Y��ݒ�

	SetMouseDispFlag(TRUE);      // �}�E�X�J�[�\���̕\��

	SetDrawScreen(DX_SCREEN_BACK);

	// Effekseer�֘A
	SetUseDirect3DVersion(DX_DIRECT3D_11);      // DirectX11���g�p

	if (DxLib_Init() == -1)		// DX���C�u������Effekseer�̏���������
	{
		return false;			// �G���[���N�����璼���ɏI��
	}

	if (Effekseer_Init(8000) == -1)		// DX���C�u������Effekseer�̏���������
	{
		return false;			// �G���[���N�����璼���ɏI��
	}

	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	// �J����
	m_camera = new Camera();
	// ����
	m_input = new Input();

	return true;
}

// ��������
void GameSystem::Create()
{
	// �^�C�g��
	m_titleScene = new SceneTitle();
	m_titleScene->Initialize();
	// �Q�[����
	m_inGameScene = new SceneInGame();
	m_inGameScene->Initialize();
	// ���U���g
	m_resultScene = new SceneResult();
	m_resultScene->Initialize();

}

// �폜
void GameSystem::Delete()
{
	// �^�C�g���̉������
	m_titleScene->Delete();
	// �C���Q�[���̉������
	m_inGameScene->Delete();
	// ���U���g�̉������
	m_resultScene->Delete();

	delete (m_titleScene);
	delete (m_inGameScene);
	delete (m_resultScene);
}

// �X�V����
int GameSystem::Update()
{
	return 0;
}

// �ړ��֘A�̍X�V
void GameSystem::UpdateMove()
{
}

// �`��֘A�̍X�V
void GameSystem::UpdateDraw()
{
}

// �G���[�Ď�
bool GameSystem::ProgramLoop()
{
	// Windows�̏����ɃG���[���N������,�܂���Esc�ŏI��
	if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE))
	{
		return false;
	}

	return true;
}

// �Q�[�����[�v
void GameSystem::RunLoop()
{
	// ���ݎ���, �O�񎞍����L�^����
	DWORD nowTick, prevTick;
	prevTick = timeGetTime();

	Create();

	while (ProgramLoop())
	{
		//���Ԍv��
		nowTick = timeGetTime();
		DWORD m_Ticks = nowTick - prevTick;
		prevTick = timeGetTime();

		m_deltaTime = m_Ticks / 1000.0f;
		prevTick = nowTick;

		ClearDrawScreen();

		// Effekseer���̃J������Dx���C�u�������̃J�����𓯊�����
		Effekseer_Sync3DSetting();

		// �o�^�p�b�h�̍X�V
		m_input->ScanPadNum(PAD_NUM::PLAYER_1);

		// �V�[�����ƂɍX�V����
		switch (sceneNum)
		{
		case SCENE_PHASE::INIT:
			Create();
			sceneNum = SCENE_PHASE::START;
			break;

		case SCENE_PHASE::START:
			m_titleScene->Update(*m_camera, *m_input, m_deltaTime);
			sceneNum = m_titleScene->GetNextScene();
			break;

		case SCENE_PHASE::TUTORIAL:
			sceneNum = SCENE_PHASE::GAME;
			break;

		case SCENE_PHASE::GAME:
			// �V�[���̍X�V
			m_inGameScene->Update(*m_camera, *m_input, *m_resultScene, m_deltaTime);
			sceneNum = m_inGameScene->GetNextScene();
			break;

		case SCENE_PHASE::GAME_END:
			m_resultScene->Update(*m_camera, *m_input, m_deltaTime);
			m_resultScene->Draw();
			sceneNum = m_resultScene->GetNextScene();
			break;

		case SCENE_PHASE::SHUT_DOWN:
			Delete();
			sceneNum = SCENE_PHASE::INIT;
			break;

		default:
			break;
		}

		// Effekseer�̍X�V
		UpdateEffekseer3D();
		// Effekseer�̕`��
		DrawEffekseer3D();

		ScreenFlip();
	}

	ShutDown();

	Effkseer_End();
	DxLib_End();
}

// �I������
void GameSystem::ShutDown()
{
	Delete();
	delete (m_camera);
	delete (m_input);
}

// ��ʏ��(width : ����, Height : �c��, �S��ʕ\�����ǂ���)�̃Z�b�^�[
void GameSystem::SetScreen(const int & scrWidth, const int & scrHeight, const bool & fullScreen)
{
	m_screenWidth = scrWidth;
	m_screenHeight = scrHeight;
	m_fullScreen = fullScreen;
}
