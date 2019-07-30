//-----------------------------------------------------------------------+
// �X�R�A�N���X                                 
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "Score.h"

const int Score::SCORE_POINT = 100;       // �X�R�A���Z�p�|�C���g
const double Score::SCORE_MULTIPLE[5] = { 1, 2, 3, 3.5, 4 };

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
}

void Score::Delete()
{
	
}

// �X�V����
void Score::Update(Player& player)
{
	// �v���C���[�̏����A�C�e����ǐ�
	m_holdScore = player.GetHoldItem();

	// �v���C���[�̉���t���O����������X�R�A�����Z���A�t���O��܂�
	if (player.GetDeliveredItem() == true)
	{
		// �X�R�A�ɉ��Z:�v���C���[�̏������Ă���A�C�e�� * ��{�X�R�A�|�C���g * �����A�C�e�����ɂ��{��
		m_score += player.GetHoldItem() * SCORE_POINT * SCORE_MULTIPLE[player.GetHoldItem() - 1];
		player.InitHoldItem();
		player.SetDeliveredItem(false);
	}
}

// �`�揈��
void Score::Draw()
{
	// �X�R�A�̕\��
	DrawFormatString(0, 450, GetColor(255, 255, 255), "%d", m_score);
	// �z�[���h��Ԃ̃X�R�A��\��
	DrawFormatString(0, 500, GetColor(255, 255, 255), "%d", m_holdScore);
}
