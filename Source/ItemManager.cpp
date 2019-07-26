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

	// �A�C�e���̏������W�Z�b�g(�����_��)
	for (auto item : m_item)
	{
		item->SetEmergence(GetRandomPosition());
	}
}

// �������
void ItemManager::Delete()
{
	// �A�C�e���̍폜
	while (!m_item.empty())
	{
		delete m_item.back();
	}
	m_item.clear();
}

// �X�V����
void ItemManager::Update(float deltaTime)
{
	// �A�C�e���̍X�V����
	for (auto item : m_item)
	{
		// �o����ԂȂ痎��������
		if (item->GetState() == Item::POP)
		{
			item->Fall(deltaTime);
		}

		// �A�N�e�B�u��ԂȂ�A�b�v�f�[�g
		if (item->GetState() == Item::ACTIVE)
		{
			item->Update();
		}
	}
}

// �`�揈��
void ItemManager::Draw()
{
	// �A�C�e���̕`�揈��
	for (auto item : m_item)
	{
		item->Draw();
	}
}

// �t�B�[���h�ւ̃A�C�e���ǉ�
void ItemManager::AddItem()
{
	// �t�B�[���h��̃A�C�e���̑������ő�l��菭�Ȃ�������
	if (m_numOnField < ITEM_MAX)
	{
		// �ǉ�
		m_item.emplace_back(new Item(m_sourceModelHandle));

		// �o���ʒu�̐ݒ�(�����_��)
		m_item.back()->SetEmergence(GetRandomPosition());
	}

}

// �����_���ȏo���ʒu�̃Q�b�^�[
const VECTOR & ItemManager::GetRandomPosition() const
{
	VECTOR randPos;



	return randPos;
}
