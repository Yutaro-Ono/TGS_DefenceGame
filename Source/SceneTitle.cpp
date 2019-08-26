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
	m_alpha = 255;
	m_alphaCount = false;
	// �^�C�g�����S�摜�����[�h�A�T�C�Y�擾
	m_titleLogoGraph = LoadGraph("Data/Interface/Title_Logo_2.png");
	// �^�C�g�����S�̉摜�T�C�Y���擾
	GetGraphSize(m_titleLogoGraph, &m_titleLogoW, &m_titleLogoH);
	// �w�i�̃G�t�F�N�g
	m_bgEffect = new PlayEffect("Data/Effects/UI_BgStarDust.efk");
	m_bgEffect->Initialize();
	// �Đ�����BGM
	m_bgm = new SoundFX("Data/Music/BGM/Title/cyrf_lu_main_theme.mp3");

	m_text = new TextGraph();
	m_text->Initialize();
}

void SceneTitle::Delete()
{
	m_bgEffect->Delete();
	m_bgm->Delete();

	m_text->Delete();

	delete (m_bgEffect);
	delete (m_bgm);

	delete (m_text);
}

void SceneTitle::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM�Đ�
	m_bgm->PlayLoopSoundFx();

}

void SceneTitle::Draw()
{

	if (m_alpha >= 255)
	{
		m_alphaCount = false;
	}
	if (m_alpha <= 32)
	{
		m_alphaCount = true;
	}

	if (m_alphaCount == true)
	{
		m_alpha += 2;
	}
	if (m_alphaCount == false)
	{
		m_alpha -= 2;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);       // �u�����h���[�h(����)���I��
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //�u�����h���[�h���I�t

	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 700, GAME_INSTANCE.GetScreenHeight() / 2 + 50, "�ł��邾�������̐����W�߂Ē��S�̃|�b�h�֎����Ă������I", GetColor(255, 255, 255));
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 100, "UFO�ɓ�����ƃ_���[�W�I", GetColor(255, 255, 255));
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 350, GAME_INSTANCE.GetScreenHeight() / 2 + 250, "START�{�^��orSPACE�L�[�ŃX�^�[�g", GetColor(255, 255, 255));

	// �G�t�F�N�g�̍Đ�
	if (m_bgEffect->GetNowPlaying() == -1)
	{
		m_bgEffect->PlayEffekseer(VGet(700.0f, -150.0f, 0.0f));
		m_bgEffect->SetEffectScale(100.0f, 100.0f, 100.0f);
	}

	m_text->DrawTextMessage(0, 100, "PRESS ANY KEY");

	// Effekseer�̍X�V
	UpdateEffekseer3D();
	// Effekseer�̕`��
	DrawEffekseer3D();
}

// ���̃V�[���ւ̑J�ڏ��� (�V�[���J�ڏ�����true�������玟�V�[���ւ̃|�C���^��Ԃ��Afalse�������炱�̃N���X�̃|�C���^��Ԃ�)
SceneBase * SceneTitle::SceneUpdate(Input& input)
{
	// START�{�^�����X�y�[�X�L�[�Ŏ��̃V�[����
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START) || CheckHitKey(KEY_INPUT_SPACE))
	{
		m_bgm->StopSoundFx();
		Delete();                         // �������

		return new SceneInGame();           // ���̃V�[����Ԃ�
	}

	return this;
}
