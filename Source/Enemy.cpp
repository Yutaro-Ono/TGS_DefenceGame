//-----------------------------------------------------------------------+
// �G�l�~�[�N���X                            
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "Enemy.h"
// �R���X�g���N�^
Enemy::Enemy(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �e�평��������
void Enemy::Initialize()
{

}

// �o���ʒu�ݒ�
void Enemy::SetEmergence(const VECTOR popPos)
{
	m_position = popPos;

	MV1SetPosition(m_modelHandle, m_position);
}

// �^�[�Q�b�g�̕����Ɍ���
void Enemy::GazeTarget()
{

}
