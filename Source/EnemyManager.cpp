//-----------------------------------------------------------------------+
// �G�l�~�[�}�l�[�W���[�N���X                              
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "EnemyManager.h"

const int EnemyManager::ENEMY_MAX_NUM = 5;           // �G�̈�x�ɏo������ő吔
const int EnemyManager::ENEMY_ALL_NUM = 25;          // �G�̍��v��

// �e�평����(���f���̓ǂݍ��݁A�|�W�V�����ݒ�)
void EnemyManager::Initialize()
{
	// �G�l�~�[���f���̓ǂݍ���
	m_enemySourceHandle = MV1LoadModel("Data/Model/Actor/Enemy/Low_poly_ufo_FBX/Low_poly_UFO.mv1");

	// �G�l�~�[�̐���
	for (int i = 0; i < ENEMY_ALL_NUM; i++)
	{
		m_enemy.push_back(new Enemy(m_enemySourceHandle));
	}

	// �o���ʒu�̐ݒ�(�~�`)
	for (int i = 0; i < m_enemy.size(); i++)
	{
		// cos((360.0f - (360.0f / enemy.size()) * i) * PI / 180.0f)
		//                                                   ���a
		m_enemy[i]->SetEmergence(VGet(cos((360.0f - (360.0f / m_enemy.size()) * i) * PI / 180.0f) * 120.0f, 0, 40.0f + sin(((360.0f / m_enemy.size()) * i) * PI / 180.0f) * 120.0f));
	}
}

// �e��������
void EnemyManager::Delete()
{
	// ���f�����폜
	MV1DeleteModel(m_enemySourceHandle);
	
	for (int i = 0; i < ENEMY_ALL_NUM; i++)
	{
		delete (m_enemy[i]);
		m_enemy[i] = NULL;
	}

}

// �X�V����
void EnemyManager::Update(PlayerManager& playerManager, float deltaTime)
{
	for (int i = 0; i < m_enemy.size(); i++)
	{
		if (!m_enemy[i]->GetHitPlayer())
		{
			m_enemy[i]->Update(deltaTime);
			m_enemy[i]->GazeTarget(playerManager, deltaTime);
		}
	}
}

// �`�揈��
void EnemyManager::Draw()
{
	for (int i = 0; i < m_enemy.size(); i++)
	{
		m_enemy[i]->Draw();
	}
}
