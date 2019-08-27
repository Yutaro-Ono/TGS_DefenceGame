//-----------------------------------------------------------------------+
// ���U���g�V�[��                         
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+
#include "SceneResult.h"

SceneResult::SceneResult(bool in_isGameOver)
	:toNext(4)
{
	// �Q�[�����N���A�������ǂ���
	m_gameOver = in_isGameOver;
}

SceneResult::~SceneResult()
{
}

// �e�평��������
void SceneResult::Initialize()
{
	m_bgm = new SoundFX("Data/Music/BGM/Result/cyrf_dreamland.mp3");
}

// �e��������
void SceneResult::Delete()
{
	m_bgm->Delete();
	delete (m_bgm);
}

// �X�V����
void SceneResult::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM�Đ�
	m_bgm->PlayLoopSoundFx();
}

// �`�揈��
void SceneResult::Draw(TextGraph& text)
{
	// �Q�[���I�[�o�[���ǂ����ŏ����𕪊�
	if (m_gameOver == false)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "�����c�ꂽ");
	}
	if (m_gameOver == true)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "�����c��Ȃ�����");
	}

	// ���g���C,�I���̃`���[�g���A��
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 50, GetColor(255, 255, 255), "START�Ń��g���C");
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 100, GetColor(255, 255, 255), "ESCAPE�ŏI��");
}

// �V�[���̍X�V����
SceneBase * SceneResult::SceneUpdate(Input & input)
{
	// START��ENTER�Ŏ��̃V�[����
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START) || CheckHitKey(KEY_INPUT_RETURN))
	{
		m_bgm->StopSoundFx();       // ���y���~
		Delete();                   // �������
		// ���̃V�[����Ԃ�
		return new SceneTitle();
	}

	// BACK�ŏI��
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_BACK))
	{
		Delete();

		GAME_INSTANCE.SetGameQuit(true);
	}

	// ����������Ȃ���Ύ��g�̃|�C���^��Ԃ�
	return this;
}
