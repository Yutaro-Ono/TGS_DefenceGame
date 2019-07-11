//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�V�[��                               
//                                              Last Update : 2019/07/01
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "PlayerManager.h"
#include "Camera.h"
#include "HitChecker.h"

// �R���X�g���N�^
SceneInGame::SceneInGame()
{
	m_player = NULL;
	m_enemy = NULL;
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
	// �G�l�~�[�𐶐��C������
	m_enemy = new EnemyManager();
	m_enemy->Initialize();
	// UI�𐶐��A������
	m_UI = new InGameUIManager();
	m_UI->Initialize();
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
	delete (m_enemy);
	delete (m_obj);
	delete (m_npc);
	delete (m_UI);
}

// �X�V����
void SceneInGame::Update(Input& input, Camera& camera, float deltaTime)
{
	// �L�[�̉�����ԃ`�F�b�N
	input.KeyChecker();

	// �J�����̍X�V
	camera.Update(*m_player);

	// �����蔻�菈��
	HitChecker::CheckHit(*m_player, *m_enemy);
	for (int i = 0; i < ALL_ENEMY; i++)
	{
		HitChecker::CheckHitEnemy(*m_enemy, i);
	}

	// �v���C���[�̍X�V
	m_player->Update(input, deltaTime);
	// �G�l�~�[�̍X�V
	m_enemy->Update(*m_player, deltaTime);
	// NPC�̍X�V
	m_npc->Update(deltaTime);



	Draw();

}

// �`�揈��
void SceneInGame::Draw()
{
	// �I�u�W�F�N�g�̕`��
	m_obj->Draw();
	// �G�l�~�[�̕`��
	m_enemy->Draw();
	// �v���C���[�̕`��
	m_player->Draw();
	// UI�̕`��
	m_UI->Draw(*m_player->GetPlayerPointer());
	// NPC�̕`��
	//m_npc->Draw();
}
