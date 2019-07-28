//-----------------------------------------------------------------------+
// �A�C�e���}�l�[�W���[�N���X           
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "ItemManager.h"

const int ItemManager::ITEM_START_NUM = 3;       // �J�n���̃A�C�e������
const int ItemManager::ITEM_MAX = 15;            // �A�C�e���̍ő吔

// �R���X�g���N�^
ItemManager::ItemManager()
	:m_sourceModelHandle(-1)
{
	// �����Ȃ�
}

// �f�X�g���N�^
ItemManager::~ItemManager()
{
	// �����Ȃ�
}

// ����������
void ItemManager::Initialize()
{

	// ���f���̃��[�h
	m_sourceModelHandle = MV1LoadModel("Data/Model/Item/Score/20facestar.mv1");

	// �G���[�\�L
	if (m_sourceModelHandle == -1)
	{
		printfDx("���f�����[�h���s : �A�C�e��");
	}

	// �����A�C�e���̐���
	for (int i = 0; i < ITEM_START_NUM; i++)
	{
		m_item.emplace_back(new Item(m_sourceModelHandle));
	}

	// �A�C�e���̏������W�Z�b�g(�����_��)
	for (auto item : m_item)
	{
		item->Initialize();
		item->SetEmergence(GetRandomPosition(100.0f, 100.0f));
	}
}

// �������
void ItemManager::Delete()
{
	// ���f���̍폜
	MV1DeleteModel(m_sourceModelHandle);

	// �A�C�e���̍폜
	while (!m_item.empty())
	{
		delete m_item.back();
	}
	// �A�C�e���x�N�g���̃N���A
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
			item->Update();
			item->Draw();
		}

		// �A�N�e�B�u��ԂȂ�A�b�v�f�[�g
		if (item->GetState() == Item::ACTIVE)
		{
			item->Update();
			item->Draw();
		}

		// �f�B�A�N�e�B�u��ԂȂ�
		if (item->GetState() == Item::DEACTIVE)
		{

		}

		// ������ꂽ�����
		if (item->GetState() == Item::DEAD)
		{
			m_item.clear();
		}
	}
}

// �t�B�[���h�ւ̃A�C�e���ǉ�
void ItemManager::AddItem()
{
	// �t�B�[���h��̃A�C�e���̑������ő�l��菭�Ȃ�������
	if (m_item.size() < ITEM_MAX)
	{
		// �Ō���ɐ���
		m_item.emplace_back(new Item(m_sourceModelHandle));
		// ���������A�C�e���̏�����
		m_item.back()->Initialize();
		// �o���ʒu�̐ݒ�(�����_��)
		m_item.back()->SetEmergence(GetRandomPosition(100.0f, 100.0f));
	}
}

// �����_���ȏo���ʒu�̃Q�b�^�[
const VECTOR & ItemManager::GetRandomPosition(const float sizeFieldX, const float sizeFieldZ) const
{
	VECTOR randPos = VGet(0.0f, 20.0f, 0.0f);

	// X���W�̃|�W�V�����ݒ�
	randPos.x = GetRand(sizeFieldX);

	// Z���W�̃|�W�V�����ݒ�
	randPos.z = GetRand(sizeFieldZ);

	// X���W�̐����ݒ�
	if (GetRand(1) == 0)
	{
		randPos.x *= -1.0f;
	}
	// Z���W�̐����ݒ�
	if (GetRand(1) == 0)
	{
		randPos.z *= -1.0f;
	}

	return randPos;
}
