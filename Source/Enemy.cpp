//-----------------------------------------------------------------------+
// �G�l�~�[�N���X                            
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "Enemy.h"

const VECTOR Enemy::SCALE_SIZE = { 0.3f, 0.3f, 0.3f };
const float Enemy::MOVE_SPEED = 93.0f;

// �R���X�g���N�^
Enemy::Enemy(int sourceModelHandle)
	:Actor(sourceModelHandle)
	,m_hitRadius(10.0f)
	,m_hitPlayer(false)
{
	// �e�평����
	m_position = VGet(0.0f, 0.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_hitTime = 0;
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
	
	// �����n�ʂɖ��܂��Ă������ɉ����o��
	if (m_position.y < 0.0f)
	{
		m_position.y = 0.0f;
	}

	// ���f���̈ʒu��ݒ�
	MV1SetPosition(m_modelHandle, m_position);
}

void Enemy::Draw()
{
	MV1DrawModel(m_modelHandle);
	// �����蔻��m�F�p�̋�
	//DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

// �o���ʒu�ݒ�
void Enemy::SetEmergence(const VECTOR popPos)
{
	m_position = popPos;

	// �X�P�[��(�g�嗦)�̒���
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	
	// �`�悷����W��ݒ�
	MV1SetPosition(m_modelHandle, m_position);
}

void Enemy::HitInterval()
{
	// �����蔻��t���O����������
	if (m_hitPlayer == true)
	{
		// 1.5�b���܂�
		if (GetNowCount() - m_hitTime >= 1500)
		{
			m_hitTime = 0.0f;
		}

		// �C���^�[�o�������������ꂽ�瓖���蔻��t���O����������
		if (m_hitTime == 0.0f)
		{
			m_hitPlayer = false;
		}
	}
}

// ���̃G�l�~�[�ɓ���������
void Enemy::OnHitOtherEnemy(Enemy& other_enemy)
{
	// �������g�̈ʒu����Q���̂����蔻�蕪���炷.
    // Z����X���̓񎟌����W�Ƃ��Ĉʒu���炵���s��.
	VECTOR yZeroPlayer = VGet(m_position.x, 0, m_position.z);
	VECTOR yZeroObstruct = VGet(other_enemy.GetPosition().x, 0, other_enemy.GetPosition().z);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// �Ԃ������Ƃ��ɗ��������B���傤�ǂ���float�덷�ŏd�Ȃ葱����̂ŏ����Ԃ�������.
	float awayRange = (m_hitRadius + other_enemy.GetRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	m_position = VAdd(yZeroObstruct, awayVec);

}

// �^�[�Q�b�g(�v���C���[)�̒ǐՏ���
void Enemy::ChaseTarget(PlayerManager& playerManager, float deltaTime)
{
	// �v���C���[�ɓ����������̓X�g�b�v
	if(m_hitPlayer == false)
	{
		Actor* player = playerManager.GetPlayerPointer();
		VECTOR pVec = player->GetPosition();
		// �ڕW�܂ł̋������o
		m_targetVec.x = pVec.x - m_position.x;
		m_targetVec.z = pVec.z - m_position.z;

		// �p�x�ƈړ��ʂ��擾
		m_angle = atan2(m_targetVec.z, m_targetVec.x);

		m_position.x += cos(m_angle + MOVE_SPEED);
		m_position.z += sin(m_angle + MOVE_SPEED);
	}
}
