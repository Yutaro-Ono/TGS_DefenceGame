//-----------------------------------------------------------------------+
// �^�C�g���V�[��                  
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "SceneTitle.h"
#include "Input.h"
#include "GameSystem.h"

// �R���X�g���N�^
SceneTitle::SceneTitle()
	:m_toNext(false)
{
	// �����Ȃ�
}

// �f�X�g���N�^
SceneTitle::~SceneTitle()
{
	// �����Ȃ�
}

// ����������
void SceneTitle::Initialize()
{
	// �A���t�@�l���ő�ɂ��Ă���
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
	// ���艹
	m_enterSE = new SoundFX("Data/Music/SE/System/Enter/decision17.mp3");
}


// �������
void SceneTitle::Delete()
{
	m_bgEffect->Delete();
	m_bgm->Delete();
	m_enterSE->Delete();

	delete (m_bgEffect);
	delete (m_bgm);
	delete (m_enterSE);
}

void SceneTitle::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM�Đ�
	m_bgm->PlayLoopSoundFx();
}

// �`�揈��
void SceneTitle::Draw(TextGraph& text)
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

	// ���S�̕\��
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);              // �u�����h���[�h(����)���I��
	// �e�L�X�g�̕`��
	text.DrawTextMessage(680, 700, "PRESS START BUTTON");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);                  //�u�����h���[�h���I�t

	// �G�t�F�N�g�̍Đ�
	if (m_bgEffect->GetNowPlaying() == -1)
	{
		m_bgEffect->PlayEffekseer(VGet(700.0f, -150.0f, 0.0f));
		m_bgEffect->SetEffectScale(100.0f, 100.0f, 100.0f);
	}

}

// ���̃V�[���ւ̑J�ڏ��� (�V�[���J�ڏ�����true�������玟�V�[���ւ̃|�C���^��Ԃ��Afalse�������炱�̃N���X�̃|�C���^��Ԃ�)
SceneBase * SceneTitle::SceneUpdate(Input& input)
{
	// START�{�^�����X�y�[�X�L�[�Ŏ��̃V�[����
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START) || CheckHitKey(KEY_INPUT_SPACE))
	{
		m_toNext = true;                    // ���V�[���ֈړ�����t���O���I��
		m_enterSE->PlaySoundFx();           // ���艹��炷
	}
	// ���艹�̍Đ����I������������A���̃V�[����Ԃ�
	if (m_toNext == true && m_enterSE->ScanNowPlaySound() == true)
	{
		m_bgm->StopSoundFx();               // BGM�͎~�߂�
		return new SceneInGame();           // ���̃V�[����Ԃ�
	}

	return this;
}
