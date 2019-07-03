//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�V�[��                               
//                                              Last Update : 2019/07/01
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "PlayerManager.h"
#include "Camera.h"

// �R���X�g���N�^
SceneInGame::SceneInGame()
{
	m_player = NULL;
}

// �f�X�g���N�^
SceneInGame::~SceneInGame()
{
}

// �e�평��������
void SceneInGame::Initialize()
{
	// �v���C���[�𐶐��C������
	m_player = new PlayerManager();
	m_player->Initialize();
	// �I�u�W�F�N�g�𐶐��C������
	m_obj = new ObjectManager();
	m_obj->Initialize();
	// NPC�𐶐��C������
	m_npc = new NpcManager();
	m_npc->Initialize();
}

// �e��������
void SceneInGame::Delete()
{
	delete (m_player);
	delete (m_obj);
	delete (m_npc);
}

// �X�V����
void SceneInGame::Update(Camera& camera)
{
	// �J�����̍X�V
	camera.Update(*m_player);
	// �v���C���[�̍X�V
	m_player->Update();
	// NPC�̍X�V
	m_npc->Update();
}

// �`�揈��
void SceneInGame::Draw()
{
	// �I�u�W�F�N�g�̕`��
	m_obj->Draw();
	// �v���C���[�̕`��
	m_player->Draw();
	// NPC�̕`��
	m_npc->Draw();
}
