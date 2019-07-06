//-----------------------------------------------------------------------+
// �G�l�~�[�N���X                            
//                                              Last Update : 2019/07/03
//-----------------------------------------------------------------------+
#include "Enemy.h"

const VECTOR Enemy::SCALE_SIZE = { 0.3f, 0.3f, 0.3f };
const float Enemy::MOVE_SPEED = 3.0f;

// �R���X�g���N�^
Enemy::Enemy(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_targetVec = VGet(0.0f, 0.0f, 0.0f);
}

// �f�X�g���N�^
Enemy::~Enemy()
{
}

// �e�평��������
void Enemy::Initialize()
{
	m_angle = GetRand(180);
}

void Enemy::Update(float deltaTime)
{
	// �p�x��ݒ�
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle / 180.0f * DX_PI_F, 0.0f));


	MV1SetPosition(m_modelHandle, m_position);
}

// �o���ʒu�ݒ�
void Enemy::SetEmergence(const VECTOR popPos)
{
	m_position = popPos;

	MV1SetScale(m_modelHandle, SCALE_SIZE);

	MV1SetPosition(m_modelHandle, m_position);
}

// �^�[�Q�b�g�̕����Ɍ���
void Enemy::GazeTarget(PlayerManager& playerManager, float deltaTime)
{
	Actor* player = playerManager.GetPlayerPointer();
	VECTOR pVec = player->GetPosition();
	// �ڕW�܂ł̋������o
	m_targetVec.x = pVec.x - m_position.x;
	m_targetVec.z = pVec.z - m_position.z;

	// �p�x�ƈړ��ʂ��擾
	m_angle = atan2(m_targetVec.z, m_targetVec.x);

	m_position.x += cos(m_angle * MOVE_SPEED);
	m_position.z += sin(m_angle * MOVE_SPEED);
}
