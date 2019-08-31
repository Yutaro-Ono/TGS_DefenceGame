#include "InterfacePlayer.h"

#pragma warning (disable:4996)

InterfacePlayer::InterfacePlayer()
{
}

InterfacePlayer::~InterfacePlayer()
{
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
	m_getPosition = VGet(0.0f, 10.0f, 0.0f);

	m_get = false;
	m_getScore = 0;
}

void InterfacePlayer::Update()
{
}

void InterfacePlayer::Update(Player & player, Score& score)
{
	// �v���C���[�̍��W��ǐ�
	m_stockPosition = ConvWorldPosToScreenPos(player.GetPosition());

	// �v���C���[�̃X�R�A��

	// �X�R�A���擾�����t���O���I�t�Ŋ��v���C���[���A�C�e�����|�b�h�ɉ^�э��񂾎�
	if (m_get == false && player.GetDeliveredItem() == true)
	{
		// �擾�t���O���I��
		m_get = true;
	}

	// �v���C���[�̏����A�C�e�������X�V
	m_holdItem = player.GetHoldItem();
}

// �`�揈��
void InterfacePlayer::Draw(Player& player, TextGraph& text)
{
	for (int i = 0; i < player.GetHitPoint(); i++)
	{
		DrawGraph(0, 0, hpGauge[i], TRUE);
	}

	DrawGraph(0, 0, hpFrame, TRUE);

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


	// �擾�����X�R�A�̕`��(�|�b�h��)
	if (m_get == true)
	{

	}
}
