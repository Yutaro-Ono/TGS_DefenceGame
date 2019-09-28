//-----------------------------------------------------------------------+
// �Q�[���V�X�e���N���X                         
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// �C���N���[�h�t�@�C��
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
	,m_deltaTime(0.0f)
	,m_score(0)
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

	SetFontSize(50);                                          // �g�p����t�H���g�T�C�Y��ݒ�
	SetMouseDispFlag(TRUE);                                   // �}�E�X�J�[�\���̕\��
	SetDrawScreen(DX_SCREEN_BACK);                            // �`���𗠉�ʂɃZ�b�g

		// DX���C�u������Effekseer�̏���������
	if (DxLib_Init() == -1 || Effekseer_Init(8000) == -1)
	{
		return false;			                              // �G���[���N�����璼���ɏI��
	}

	//---------------------------------------------------+
    // Effekseer�֘A�̏�����
    //---------------------------------------------------+
	SetUseDirect3DVersion(DX_DIRECT3D_11);                    // DirectX11���g�p
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	Effekseer_SetGraphicsDeviceLostCallbackFunctions();
	SetUseZBuffer3D(TRUE);                                    // ZBuffer���g�p
	SetWriteZBuffer3D(TRUE);                                  // ZBuffer�ւ̏������݂�����

	return true;
}

// ��������
void GameSystem::Create()
{
	// �J�����𐶐�
	m_camera = new Camera();
	// ���̓V�X�e���𐶐�
	m_input = new Input();
	// �t�H���g�V�X�e���𐶐�
	m_text = new TextGraph();
	m_text->Initialize();
	// �V�[���𐶐�(�^�C�g��)
	m_scene = new SceneTitle();
	m_scene->Initialize();
}

// �������
void GameSystem::Delete()
{
	m_scene->Delete();
}

// �X�V����
int GameSystem::Update()
{
	return 0;
}

// �G���[�Ď�
bool GameSystem::ProgramLoop()
{
	// Windows�̏����ɃG���[���N������,�܂���Esc�L�[,BACK�{�^���ŏI��
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

	// �V�[���̐�������
	Create();

	while (ProgramLoop() || m_isGameQuit == true)
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

		//----------------------------------------------------+
		// �Q�[���V�[���̍X�V����
		//----------------------------------------------------+
		// �V�[���̍X�V����
		m_scene->Update(*m_camera, *m_input, m_deltaTime);

		// ���̃V�[����tmp�Ɉꎞ�擾
		m_tmpScene = m_scene->SceneUpdate(*m_input);


		// �V�[�����ύX����Ă��Ȃ������ꍇ�͕`������s
		if (m_tmpScene == m_scene)
		{
			// �`�揈��
			m_scene->Draw(*m_text);
			// Effekseer�̍X�V
			UpdateEffekseer3D();
			// Effekseer�̕`��
			DrawEffekseer3D();

			ScreenFlip();
		}
		// �V�[�����ύX����Ă����ꍇ�͕`����X�L�b�v���ăV�[�������X�V
		else
		{
			ScreenFlip();
			// ���[�h���̃e�L�X�g�\��
			m_text->DrawTextMessage(1450, 1030, "NOW LOADING...");
			ScreenFlip();

			// �������
			m_scene->Delete();
			// ���̃V�[�����i�[��������
			m_scene = m_tmpScene;
			m_scene->Initialize();
		}

		// BACK�{�^���Ń��[�v�𔲂���
		if (m_input->GetPushButtonState(XINPUT_BUTTON::XINPUT_BACK))
		{
			break;
		}
	}

	// �I������
	ShutDown();

	Effkseer_End();
	DxLib_End();

	// ���������[�N���o
	// _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

// �I������
void GameSystem::ShutDown()
{
	Delete();
	m_text->Delete();

	delete (m_scene);
	delete (m_tmpScene);
	delete (m_camera);
	delete (m_input);
	delete (m_text);
}

// ��ʏ��(width : ����, Height : �c��, �S��ʕ\�����ǂ���)�̃Z�b�^�[
void GameSystem::SetScreen(const int & scrWidth, const int & scrHeight, const bool & fullScreen)
{
	m_screenWidth = scrWidth;
	m_screenHeight = scrHeight;
	m_fullScreen = fullScreen;
}