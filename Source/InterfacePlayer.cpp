//-----------------------------------------------------------------------+
// �C���^�[�t�F�[�X(�v���C���[�X�e�[�^�X)�N���X                                     
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma warning (disable:4996)

// �C���N���[�h�t�@�C��
#include "InterfacePlayer.h"

// �R���X�g���N�^
InterfacePlayer::InterfacePlayer()
{
	// �����Ȃ�
}

// �f�X�g���N�^
InterfacePlayer::~InterfacePlayer()
{
	// �����Ȃ�
}

// ����������
void InterfacePlayer::Initialize()
{
	// �̗̓Q�[�W�̃��[�h(�������邢�R�[�h)
	for (int i = 0; i < 5; i++)
	{
		if (i == 0)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_1.png");
		}
		if (i == 1)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_2.png");
		}
		if (i == 2)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_3.png");
		}
		if (i == 3)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_4.png");
		}
		if (i == 4)
		{
			hpGauge[i] = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_5.png");
		}
	}

	// �̗̓t���[���̃��[�h
	hpFrame = LoadGraph("Data/Interface/In_GameUI/HP_GAUGE/HP_Gauge_Frame.png");

	// ���W�֘A�̏�����
	m_scorePosition = VGet(0.0f, 0.0f, 0.0f);
	m_stockPosition = VGet(0.0f, 0.0f, 0.0f);
}

// �������
void InterfacePlayer::Delete()
{
	// �����Ȃ�
}

// �X�V����
void InterfacePlayer::Update()
{
	// �����Ȃ�
}

// �X�V����(�v���C���[�ǐ�)
void InterfacePlayer::Update(Player & player)
{
	// �v���C���[�̍��W��ǐ�
	m_stockPosition = ConvWorldPosToScreenPos(player.GetPosition());

	// �v���C���[�̏����A�C�e�������X�V
	m_holdItem = player.GetHoldItem();
}

// �`�揈��
void InterfacePlayer::Draw(Player& player, TextGraph& text)
{
	for (int i = 0; i < player.GetHitPoint(); i++)
	{
		DrawGraph(0, 20, hpGauge[i], TRUE);
	}

	DrawGraph(0, 20, hpFrame, TRUE);

	//---------------------------------------------------------------------------------------+
	// �X�R�A�֘A�`��
	//---------------------------------------------------------------------------------------+
	// �X�g�b�N���̃X�R�A
	char item[5];
	sprintf(item, "+%d", m_holdItem);
	// �A�C�e����������1~99�̎��Ƀv���C���[�̓���ɕ\��
	if (m_holdItem > 0 && m_holdItem < 100)
	{
		text.DrawTextMessage(m_stockPosition.x - 60.0f, m_stockPosition.y - 110.0f, item);
	}
	// �����A�C�e����100��(���)�ɓ��B������MAX�\��
	if (m_holdItem == 100)
	{
		text.DrawTextMessage(m_stockPosition.x - 60.0f, m_stockPosition.y - 110.0f, "MAX");
	}
}
