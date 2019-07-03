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
	m_player = new PlayerManager();
	m_player->Initialize();

	m_obj = new ObjectManager();
	m_obj->Initialize();
}

// �e��������
void SceneInGame::Delete()
{
	delete (m_player);
	delete (m_obj);
}

// �X�V����
void SceneInGame::Update(Camera& camera)
{
	camera.Update(*m_player);
	m_player->Update();
}

// �`�揈��
void SceneInGame::Draw()
{
	// �v���C���[�̕`��
	m_player->Draw();
	// �I�u�W�F�N�g�̕`��
	m_obj->Draw();
}
