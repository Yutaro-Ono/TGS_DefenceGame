//-----------------------------------------------------------------------+
// �I�u�W�F�N�g�}�l�[�W���[�N���X                                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectManager.h"
#include "ObjectField.h"
#include "ObjectSky.h"

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
	m_fieldSourceHandle = MV1LoadModel("Data/Model/Field/vstage/IT_�o�����^�C���X�e�[�W������.mv1");
	// �X�J�C�h�[���̃��[�h
	m_skySourceHandle = MV1LoadModel("Data/Skydome/24-hours_SkyDome/24hours_skydome.pmx");

	// �t�B�[���h�𐶐�
	m_fieldObj = new ObjectField(m_fieldSourceHandle);
	m_fieldObj->Initialize();
	// �X�J�C�h�[���𐶐�
	m_skyObj = new ObjectSky(m_skySourceHandle);
	m_skyObj->Initialize();

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

}

// �`�揈��
void ObjectManager::Draw()
{
	// �t�B�[���h�̕`��
	m_fieldObj->Draw();
	// �X�J�C�h�[���̕`��
	m_skyObj->Draw();
}
