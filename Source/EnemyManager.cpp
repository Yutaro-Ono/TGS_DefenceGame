//-----------------------------------------------------------------------+
// �G�l�~�[�}�l�[�W���[�N���X                              
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "EnemyManager.h"

const int EnemyManager::MAX_ENEMY_NUM = 5;           // �G�̈�x�ɏo������ő吔

// �e�평����(���f���̓ǂݍ��݁A�|�W�V�����ݒ�)
void EnemyManager::Initialize()
{
	// �G�l�~�[���f���̓ǂݍ���
	m_enemySourceHandle = MV1LoadModel("Data/Model/Actor/Enemy/");
}

// �e��������
void EnemyManager::Delete()
{
	// ���f�����폜
	MV1DeleteModel(m_enemySourceHandle);


}

// �X�V����
void EnemyManager::Update()
{

}

// �`�揈��
void EnemyManager::Draw()
{

}
