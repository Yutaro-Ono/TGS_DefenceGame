//-----------------------------------------------------------------------+
// �X�R�A�N���X                                 
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "Score.h"

const int Score::SCORE_POINT = 100;       // �X�R�A���Z�p�|�C���g

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
}

// �X�V����
void Score::Update()
{

}

// �`�揈��
void Score::Draw()
{
	// �X�R�A�̕\��
	DrawFormatString(0, 500, GetColor(255, 255, 255), "%d", m_score);
}
