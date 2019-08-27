//-----------------------------------------------------------------------+
// �I�u�W�F�N�g�}�l�[�W���[�N���X                                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectManager.h"
#include "ObjectField.h"
#include "ObjectSky.h"
#include "ObjectVisibleWall.h"


// �R���X�g���N�^
ObjectManager::ObjectManager()
	:m_fieldSourceHandle(-1)
	,m_skySourceHandle(-1)
	,m_podSourceHandle(-1)
{

}

// �f�X�g���N�^
ObjectManager::~ObjectManager()
{
}

// �e�평����
void ObjectManager::Initialize()
{
	// �t�B�[���h���f���̃��[�h
	m_fieldSourceHandle = MV1LoadModel("Data/Model/Field/Field/Field_Plate.mv1");
	// �X�J�C�h�[���̃��[�h
	m_skySourceHandle = MV1LoadModel("Data/Skydome/Universe/Universe_Blue_ver.mv1");
	// ����|�b�h�̃��f�����[�h
	m_podSourceHandle = MV1LoadModel("Data/Model/Field/Collect_Pod/CollectPod.mv1");

	if (m_podSourceHandle == -1)
	{
		printfDx("�|�b�h�̃��f�������[�h�ł��Ă��܂���");
	}

	// �t�B�[���h�𐶐�
	m_fieldObj = new ObjectField(m_fieldSourceHandle);
	m_fieldObj->Initialize();
	// �X�J�C�h�[���𐶐�
	m_skyObj = new ObjectSky(m_skySourceHandle);
	m_skyObj->Initialize();
	// ����|�b�h�𐶐�
	m_podObj = new ObjectPod(m_podSourceHandle);
	m_podObj->Initialize();
}

// �e��������
void ObjectManager::Delete()
{
	// ���f���̍폜
	MV1DeleteModel(m_fieldSourceHandle);
	MV1DeleteModel(m_skySourceHandle);
	MV1DeleteModel(m_podSourceHandle);
	// �C���X�^���X��j��
	delete (m_fieldObj);
	delete (m_skyObj);
	delete (m_podObj);
}

// �X�V����
void ObjectManager::Update(float deltaTime)
{
	m_fieldObj->Update(deltaTime);
	m_podObj->Update(deltaTime);
}

// �`�揈��
void ObjectManager::Draw()
{
	// �X�J�C�h�[���̕`��
	m_skyObj->Draw();

	

	// �t�B�[���h�̕`��
	m_fieldObj->Draw();
	// ����|�b�h�̕`��
	m_podObj->Draw();
}
