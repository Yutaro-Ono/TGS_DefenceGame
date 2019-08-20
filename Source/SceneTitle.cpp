//-----------------------------------------------------------------------+
// �^�C�g���V�[��                  
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+

#include "SceneTitle.h"
#include "Input.h"
#include "GameSystem.h"

SceneTitle::SceneTitle()
	:toNext(1)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Initialize()
{
	// �^�C�g�����S�摜�����[�h�A�T�C�Y�擾
	m_titleLogoGraph = LoadGraph("Data/Interface/Title_Logo_2.png");
	// �^�C�g�����S�̉摜�T�C�Y���擾
	GetGraphSize(m_titleLogoGraph, &m_titleLogoW, &m_titleLogoH);
	// �Đ�����BGM
	m_bgm = new SoundFX("Data/Music/BGM/Title/cyrf_lu_main_theme.mp3");
}

void SceneTitle::Delete()
{
	m_bgm->Delete();
	delete (m_bgm);
}

void SceneTitle::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM�Đ�
	m_bgm->PlayLoopSoundFx();

	// A�{�^���Ŏ��̃V�[����
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START))
	{
		m_bgm->StopSoundFx();
		toNext = 3;
	}

	// �X�y�[�X�{�^���Ŏ��̃V�[����
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_bgm->StopSoundFx();
		toNext = 3;
	}
	

	//�`��
	Draw();
}

void SceneTitle::Draw()
{
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 50, "UFO���琧�����ԓ������I", GetColor(255, 255, 255));
	
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 100, "SPACE�L�[�ŃX�^�[�g", GetColor(255, 255, 255));

}
