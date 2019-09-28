//-----------------------------------------------------------------------+
// �X�R�A�N���X                                 
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma warning(disable:4996)

// �C���N���[�h�t�@�C��
#include "Score.h"

const int Score::SCORE_POINT = 100;       // �X�R�A���Z�p�|�C���g
const double Score::SCORE_MULTIPLE[6] = { 1, 2, 3, 3.5, 4, 5 };

// �R���X�g���N�^
Score::Score()
{
	// �����Ȃ�
}

// �f�X�g���N�^
Score::~Score()
{
	// �����Ȃ�
}

// �e�평��������
void Score::Initialize()
{
	m_scorePosition = VGet(1700.0f, 20.0f, 0.0f);
	m_score = 0;
	m_holdScore = 0;

	m_addPosition = VGet(1650.0f, 60.0f, 0.0f);
	m_addScore = false;

	m_timer = new Timer();
	m_timer->Initialize();
}

// �������
void Score::Delete()
{
	m_timer->Delete();
	m_timer->Initialize();
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
		// �擾�����X�R�A�͈ꎞ�ۑ�
		m_addScoreVal = player.GetHoldItem() * SCORE_POINT * score_multiple;
		// �X�R�A�̉��Z�t���O���I��
		m_addScore = true;

		// �X�R�A�̏�����
		player.InitHoldItem();
		player.SetDeliveredItem(false);
	}
}

// �`�揈��
void Score::Draw(TextGraph& text)
{
	char score[15];
	sprintf(score, "%d", m_score);

	// �X�R�A�̕\��
	text.DrawTextMessage(1500, 20, "SCORE:");
	text.DrawTextMessage(m_scorePosition.x, m_scorePosition.y, score);
}

// ���Z���X�R�A�̕\��
void Score::DrawAddScore(TextGraph& text)
{
	if (m_addScore == true)
	{
		char addScore[15];
		sprintf(addScore, "+%d", m_addScoreVal);

		// �X�R�A���Z���̕\��
		text.DrawTextMessage(m_addPosition.x, m_addPosition.y, addScore);
		if (m_timer->RunTimer(1) < 0)
		{
			m_addScore = false;
		}
	}
	else
	{
		m_timer->Initialize();
	}
}
