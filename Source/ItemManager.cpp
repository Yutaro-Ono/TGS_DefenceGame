//-----------------------------------------------------------------------+
// �A�C�e���}�l�[�W���[�N���X           
//                                              Last Update : 2019/07/25
//-----------------------------------------------------------------------+
#include "ItemManager.h"

const int ItemManager::ITEM_MAX = 3;        // �A�C�e���̍ő吔

// �R���X�g���N�^
ItemManager::ItemManager()
{
}

// �f�X�g���N�^
ItemManager::~ItemManager()
{
}


// ����������
void ItemManager::Initialize()
{
	// �t�B�[���h��̃A�C�e������������
	m_numOnField = 0;

	// ���f���̃��[�h
	m_sourceModelHandle = MV1LoadModel("Data/Model/Item/Score/20facestar.mv1");

	// �����A�C�e���̐���
	for (int i = 0; i < ITEM_MAX; i++)
	{
		m_item.emplace_back(new Item(m_sourceModelHandle));
		m_numOnField++;
	}

}

// �������
void ItemManager::Delete()
{

}

// �X�V����
void ItemManager::Update()
{
	// �A�C�e���̍X�V����
	for (auto item : m_item)
	{
		item->Update();
	}


}

// �`�揈��
void ItemManager::Draw()
{
}

// �t�B�[���h�ւ̃A�C�e���ǉ�
void ItemManager::AddItem()
{
}
