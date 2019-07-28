//-----------------------------------------------------------------------+
// �I�u�W�F�N�g�}�l�[�W���[�N���X                                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectManager.h"
#include "ObjectField.h"
#include "ObjectSky.h"
#include "ObjectVisibleWall.h"

const int ObjectManager::WALL_NUM = 25;        // �����Ȃ��ǂ̐�

// �R���X�g���N�^
ObjectManager::ObjectManager()
	:m_fieldSourceHandle(-1)
	,m_skySourceHandle(-1)
{
	// NULL�����Ă���
	for (int i = 0; i < OBJECT_NUM_H; i++)
	{
		for (int j = 0; j < OBJECT_NUM_W; j++)
		{
			m_object[i][j] = NULL;
		}
	}
}

// �f�X�g���N�^
ObjectManager::~ObjectManager()
{
}

// �e�평����
void ObjectManager::Initialize()
{
	// �t�B�[���h���f���̃��[�h
	m_fieldSourceHandle = MV1LoadModel("Data/Model/Field/�`�F�b�N�ȃh�[�����[��ver100/�`�F�b�N�ȃh�[�����[��ver100.mv1");
	// �X�J�C�h�[���̃��[�h
	m_skySourceHandle = MV1LoadModel("Data/Skydome/Universe/Universe.mv1");

	// �t�B�[���h�𐶐�
	m_fieldObj = new ObjectField(m_fieldSourceHandle);
	m_fieldObj->Initialize();
	// �X�J�C�h�[���𐶐�
	m_skyObj = new ObjectSky(m_skySourceHandle);
	m_skyObj->Initialize();

	//// �����Ȃ��ǂ𐶐�
	//for (int i = 0; i < WALL_NUM; i++)
	//{
	//	m_visibleWall.push_back(new ObjectVisibleWall);
	//}

	//for (int i = 0; m_visibleWall.size(); i++)
	//{
	//	m_visibleWall[i]->SetPosition(VGet(cos((360.0f - (360.0f / m_visibleWall.size()) * i) * PI / 180.0f) * 90.0f, 0, 40.0f + sin(((360.0f / m_visibleWall.size()) * i) * PI / 180.0f) * 90.0f));
	//}

	//// �t�B�[���h�𐶐�
	//for (int i = 0; i < OBJECT_NUM_H; i++)
	//{
	//	for (int j = 0; j < OBJECT_NUM_W; j++)
	//	{
	//		object[i][j] = new ObjectField(m_fieldSourceHandle);
	//	}
	//}
}

// �e��������
void ObjectManager::Delete()
{

	MV1DeleteModel(m_fieldSourceHandle);
	delete (m_fieldObj);
	MV1DeleteModel(m_skySourceHandle);
	delete (m_skyObj);

	//for (int i = 0; m_visibleWall.size(); i++)
	//{
	//	delete(m_visibleWall[i]);
	//	m_visibleWall[i] = NULL;
	//}

	for (int i = 0; i < OBJECT_NUM_H; i++)
	{
		for (int j = 0; j < OBJECT_NUM_W; j++)
		{
			delete (m_object[i][j]);
			m_object[i][j] = NULL;
		}
	}

	
}

// �X�V����
void ObjectManager::Update()
{
	m_fieldObj->Update();
}

// �`�揈��
void ObjectManager::Draw()
{
	// �t�B�[���h�̕`��
	m_fieldObj->Draw();
	// �X�J�C�h�[���̕`��
	m_skyObj->Draw();

	//for (int i = 0; m_visibleWall.size(); i++)
	//{
	//	m_visibleWall[i]->Update();
	//}
}
