//-----------------------------------------------------------------------+
// �Q�[���V�X�e���N���X                         
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include <iostream>
#include <Windows.h>
#include "Camera.h"
#include "GameSystem.h"
#include "SceneTitle.h"
#include "SceneInGame.h"

// �R���X�g���N�^
GameSystem::GameSystem()
	:m_screenWidth(0)
	,m_screenHeight(0)
	,m_fullScreen(false)
	,sceneNum(0)
	,m_deltaTime(0.0f)
{
	m_isGameQuit = false;
}

// �f�X�g���N�^
GameSystem::~GameSystem()
{
	// �����Ȃ�
}

bool GameSystem::Initialize()
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return false;			// �G���[���N�����璼���ɏI��
	}

	SetScreen(1600, 900, true);

	// �S��ʕ\���t���O���I�t��������E�B���h�E���[�h�ɂ���
	if (m_fullScreen)
	{
		ChangeWindowMode(TRUE);
	}

	// ��ʐݒ���X�V
	SetGraphMode(m_screenWidth, m_screenHeight, 32, 60);

	SetFontSize(50);

	SetMouseDispFlag(TRUE);      // �}�E�X�J�[�\���̕\��

	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}


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

	m_titleScene = new SceneTitle();
	m_titleScene->Initialize();
	m_inGameScene = new SceneInGame();
	m_inGameScene->Initialize();

	m_input = new Input();

	m_camera = new Camera();

	while (ProgramLoop())
	{
		//���Ԍv��
		nowTick = timeGetTime();
		DWORD m_Ticks = nowTick - prevTick;
		prevTick = timeGetTime();

		m_deltaTime = m_Ticks / 1000.0f;
		prevTick = nowTick;

		ClearDrawScreen();

		switch (sceneNum)
		{
		case SCENE_PHASE::START:
			m_titleScene->Update(*m_input, *m_camera, m_deltaTime);
			sceneNum = m_titleScene->GetNextScene();
			break;

		case SCENE_PHASE::TUTORIAL:
			break;

		case SCENE_PHASE::GAME:
			// �V�[���̍X�V
			m_inGameScene->Update(*m_input, *m_camera, m_deltaTime);
			sceneNum = m_inGameScene->GetNextScene();
			break;

		case SCENE_PHASE::GAME_END:
			break;

		default:
			break;
		}

		// �V�[���̍X�V
		//m_inGameScene->Update(*m_input, *m_camera, m_deltaTime);



		// �`��
		//m_inGameScene->Draw();

		ScreenFlip();

	}

}

// �I������
void GameSystem::ShutDown()
{
	m_inGameScene->Delete();

	delete (m_camera);
	delete (m_inGameScene);

	DxLib_End();
}

// ��ʏ��(width : ����, Height : �c��, �S��ʕ\�����ǂ���)�̃Z�b�^�[
void GameSystem::SetScreen(const int & scrWidth, const int & scrHeight, const bool & fullScreen)
{
	m_screenWidth = scrWidth;
	m_screenHeight = scrHeight;
	m_fullScreen = fullScreen;
}
