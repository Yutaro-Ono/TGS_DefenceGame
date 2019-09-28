//-----------------------------------------------------------------------+
// �Q�[�����ɂ�����C���^�[�t�F�[�X�����N���X
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "InGameUIManager.h"
#include "InterfacePlayer.h"

// �R���X�g���N�^
InGameUIManager::InGameUIManager()
{
	// �����Ȃ�
}

// �f�X�g���N�^
InGameUIManager::~InGameUIManager()
{
	// �����Ȃ�
}

// �e�평��������
void InGameUIManager::Initialize()
{
	m_score = 0;

	// �v���C���[�X�e�[�^�XUI
	m_playerUI = new InterfacePlayer();
	m_playerUI->Initialize();
	// �X�R�A
	m_score = new Score();
	m_score->Initialize();
}

// �e��������
void InGameUIManager::Delete()
{
	delete (m_playerUI);
	delete (m_score);
}

// �X�V����
void InGameUIManager::Update(Player & player)
{
	m_score->Update(player);
	m_playerUI->Update(player);

	// �X�R�A���X�V
	m_nowScore = m_score->GetScore();
}

// �`�揈��
void InGameUIManager::Draw(Player& player, TextGraph& text)
{
	// �v���C���[�X�e�[�^�X�̕`��
	m_playerUI->Draw(player, text);

	// �X�R�A�̕`��
	m_score->Draw(text);
	m_score->DrawAddScore(text);
}
