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
	m_enemySourceHandle = MV1LoadModel("Data/Model/Actor/Enemy/koibreder/koibreder.pmx");

	// �G�l�~�[�̐���
	for (int i = 0; i < ENEMY_ALL_NUM; i++)
	{
		enemy.push_back(new Enemy(m_enemySourceHandle));
	}

	// �o���ʒu�̐ݒ�(�~�`)
	for (int i = 0; i < enemy.size(); i++)
	{
		// cos((360.0f - (360.0f / enemy.size()) * i) * PI / 180.0f)
		//                                                   ���a
		enemy[i]->SetEmergence(VGet(cos((360.0f - (360.0f / enemy.size()) * i) * PI / 180.0f) * 90.0f, 0, 40.0f + sin(((360.0f / enemy.size()) * i) * PI / 180.0f) * 90.0f));
	}
}

// �e��������
void EnemyManager::Delete()
{
	// ���f�����폜
	MV1DeleteModel(m_enemySourceHandle);
	
	for (int i = 0; i < ENEMY_ALL_NUM; i++)
	{
		delete (enemy[i]);
		enemy[i] = NULL;
	}

}

// �X�V����
void EnemyManager::Update()
{

}

// �`�揈��
void EnemyManager::Draw()
{
	for (int i = 0; i < enemy.size(); i++)
	{
		enemy[i]->Draw();
	}
}