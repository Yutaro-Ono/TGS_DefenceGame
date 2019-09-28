//-----------------------------------------------------------------------+
// NPC�}�l�[�W���[�N���X                                    
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "NpcManager.h"

// �R���X�g���N�^
NpcManager::NpcManager()
{
}

// �f�X�g���N�^
NpcManager::~NpcManager()
{
}

// �e�평��������
void NpcManager::Initialize()
{
	// �A�C�h�����f�������[�h
	m_idolSourceHandle = MV1LoadModel("Data/Model/Actor/Idol/�{�肵����/miyazaki_shion.mv1");
	// �A�C�h���𐶐�
	m_idol = new Idol(m_idolSourceHandle);
}

// �e��������
void NpcManager::Delete()
{
	MV1DeleteModel(m_idolSourceHandle);
	delete (m_idol);
}

// �X�V����
void NpcManager::Update(float deltaTime)
{
	// �A�C�h���̍X�V
	m_idol->Update(deltaTime);
}

// �`�揈��
void NpcManager::Draw()
{
	// �A�C�h���̕`��
	m_idol->Draw();
}
