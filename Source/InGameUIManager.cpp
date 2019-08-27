//-----------------------------------------------------------------------+
// �Q�[�����ɂ�����C���^�[�t�F�[�X�����N���X
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "InGameUIManager.h"
#include "InterfacePlayer.h"

// �R���X�g���N�^
InGameUIManager::InGameUIManager()
{
	//m_tutorialGraph = LoadGraph("Data/Interface/Control_Tutorial.png");
}

// �f�X�g���N�^
InGameUIManager::~InGameUIManager()
{

}

// �e�평��������
void InGameUIManager::Initialize()
{
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
}

// �`�揈��
void InGameUIManager::Draw(Player& player, TextGraph& text)
{
	// �v���C���[�X�e�[�^�X�̕`��
	m_playerUI->Draw(player, text);

	// �X�R�A�̕`��
	m_score->Draw(text);

	// �`���[�g���A���摜(���ŗp)
	// DrawGraph(1280, 50, m_tutorialGraph, TRUE);
}
