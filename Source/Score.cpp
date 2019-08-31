//-----------------------------------------------------------------------+
// �X�R�A�N���X                                 
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "Score.h"
#pragma warning(disable:4996)
const int Score::SCORE_POINT = 100;       // �X�R�A���Z�p�|�C���g
const double Score::SCORE_MULTIPLE[6] = { 1, 2, 3, 3.5, 4, 5 };

Score::Score()
{
	// �����Ȃ�
}

Score::~Score()
{
	// �����Ȃ�
}

// �e�평��������
void Score::Initialize()
{
	m_score = 0;
	m_holdScore = 0;
	m_prevGetScoreValue = 0;
}

void Score::Delete()
{
	
}

// �X�V����
void Score::Update(Player& player)
{
	double score_multiple = 0.0;
	// �v���C���[�̏����A�C�e����ǐ�
	m_holdScore = player.GetHoldItem();

	// �v���C���[�̉���t���O����������X�R�A�����Z���A�t���O��܂�
	if (player.GetDeliveredItem() == true)
	{
		// �A�C�e�������������ȏ�Ȃ�{�����ő�ɐݒ�
		if (player.GetHoldItem() >= 6)
		{
			score_multiple = SCORE_MULTIPLE[5];
		}
		else
		{
			score_multiple = SCORE_MULTIPLE[player.GetHoldItem() - 1];
		}

		// �X�R�A�ɉ��Z:�v���C���[�̏������Ă���A�C�e�� * ��{�X�R�A�|�C���g * �����A�C�e�����ɂ��{��
		m_score += player.GetHoldItem() * SCORE_POINT * score_multiple;

		player.InitHoldItem();
		player.SetDeliveredItem(false);
	}
}

// �`�揈��
void Score::Draw(TextGraph& text)
{
	char score[15];
	sprintf(score, "%d", m_score);

	// SCORE:
	text.DrawTextMessage(1500, 0, "SCORE:");
	text.DrawTextMessage(1700, 0, score);
}
