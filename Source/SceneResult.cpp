//-----------------------------------------------------------------------+
// ���U���g�V�[��                         
//                                              Last Update : 2019/09/03
//-----------------------------------------------------------------------+
#include "SceneResult.h"

#pragma warning(disable:4996)

SceneResult::SceneResult(bool in_isGameOver, int in_score)
	:toNext(4)
{
	// �Q�[�����N���A�������ǂ���
	m_gameOver = in_isGameOver;
	// �X�R�A���i�[
	m_score = in_score;
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
	char score[20];
	sprintf(score, "SCORE : %d", m_score);


	// �Q�[���I�[�o�[���ǂ����ŏ����𕪊�
	if (m_gameOver == false)
	{
		text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, "Game Clear !!");
		// �X�R�A��\��
		text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 50, score);
	}
	if (m_gameOver == true)
	{
		text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, "Game Over ...");
	}

	// ���g���C,�I���̃`���[�g���A��
	text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 140, "START : Retry");
	text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 175, "ESCAPE : GAME END");
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
		Delete();                     // �������

		GAME_INSTANCE.SetGameQuit(true);      // �Q�[���𔲂���
	}

	// ����������Ȃ���Ύ��g�̃|�C���^��Ԃ�
	return this;
}
