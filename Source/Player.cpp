//-----------------------------------------------------------------------+
// �v���C���[�N���X                        
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Player.h"

const int Player::MAX_HP = 5;
const float Player::MOVE_SPEED = 80.0f;
const float Player::INITIAL_POSITION_Y = 5.0f;
const VECTOR Player::SCALE_SIZE = { 0.03f, 0.03f, 0.03f };
const float Player::JUMP_POWER = 12.0f;
const float Player::JUMP_SUB = 0.3f;
const int Player::MAX_HOLDITEM = 100;

// �R���X�g���N�^(Actor�̏������q��t����)
Player::Player(const int sourceModelHandle)
	:Actor(sourceModelHandle)
	,m_hitRadius(3.0f)
{

}

// �f�X�g���N�^�[
Player::~Player()
{
	// �����Ȃ�
}

void Player::Initialize()
{
	// �e�평����
	m_hitPoint = MAX_HP;
	m_moveFlag = false;
	m_hitEnemy = false;
	m_position = VGet(0.0f, 5.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_angle = 0.0f;
	m_hitTime = 0;
	velocityY = JUMP_POWER;
	m_holdItemNum = 0;
	m_deliverdItem = false;
}

// �X�V
void Player::Update(float deltaTime)
{

	//-----------------------------------------//
	// �ړ�����
	//----------------------------------------//
	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_UP)
	{
		m_position.z += MOVE_SPEED * deltaTime;
		m_angle = 0.0f;
	}

	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_DOWN)
	{
		m_position.z -= MOVE_SPEED * deltaTime;
		m_angle = -180.0f;
	}

	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_LEFT)
	{
		m_position.x -= MOVE_SPEED * deltaTime;
		m_angle = -90.0f;
	}

	if (INPUT_INSTANCE.GetKeyPad() & PAD_INPUT_RIGHT)
	{
		m_position.x += MOVE_SPEED * deltaTime;
		m_angle = 90.0f;
	}

	// �����ꂩ�̃L�[��������Ă��鎞
	if (INPUT_INSTANCE.GetKeyPad() != 0)
	{
		if (m_moveFlag == false)
		{
			m_moveFlag = true;
		}
	}

	// �ȈՓI�ȃt�B�[���h�����蔻�菈��(�t�B�[���h����͂ݏo������߂�)
	HitWallUpdate(deltaTime);

	// �ړ����[�V����
	MotionMove(deltaTime);

	// �����蔻��̃C���^�[�o������
	HitInterval();

	// ���f���̊g�嗦�Z�b�g
	MV1SetScale(m_modelHandle, SCALE_SIZE);

	// �p�x��ݒ�
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle / 180.0f * DX_PI_F, 0.0f));

	// �|�W�V�������Z�b�g
	MV1SetPosition(m_modelHandle, m_position);

	//printfDx("pos : x = %f\ny = %f\nz = %f\n", m_position.x, m_position.y, m_position.z);
}


// �ȈՓI�ȃt�B�[���h�̓����蔻��
void Player::HitWallUpdate(float deltaTime)
{
	if (m_position.x >= 110.0f)
	{
		m_position.x -= MOVE_SPEED * deltaTime;
	}
	if (m_position.x <= -110.0f)
	{
		m_position.x += MOVE_SPEED * deltaTime;
	}

	if (m_position.z >= 90.0f)
	{
		m_position.z -= MOVE_SPEED * deltaTime;
	}
	if (m_position.z <= -90.0f)
	{
		m_position.z += MOVE_SPEED * deltaTime;
	}
}

// �`�揈��
void Player::Draw()
{
	// �G�l�~�[�ɓ����������̓_�ŏ���
	if (m_hitEnemy == false || (GetNowCount() - m_hitTime) % 9)
	{
		// ���f���̕`��
		MV1DrawModel(m_modelHandle);
	}

	// �����蔻��m�F�p�̋�
	//DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

// �ړ����[�V�����ɂ����鏬���݂ȃW�����v���[�V����
void Player::MotionMove(float deltaTime)
{
	if (m_moveFlag == true)
	{
		m_position.y = velocityY;
		velocityY -= JUMP_SUB;
		if (velocityY <= INITIAL_POSITION_Y)
		{
			m_moveFlag = false;
		}
	}
	// �ړ����Ă��Ȃ��Ƃ�����Y���W�ɖ߂��AY�������x��������
	if (m_moveFlag == false)
	{
		m_position.y = INITIAL_POSITION_Y;
		velocityY = JUMP_POWER;
	}

}

// �G�l�~�[�ɓ����������̏���
void Player::OnHitEnemy(Enemy & enemy)
{
	// �������g�̈ʒu����Q���̂����蔻�蕪���炷.
    // Z����X���̓񎟌����W�Ƃ��Ĉʒu���炵���s��.
	VECTOR yZeroPlayer = VGet(m_position.x, 0, m_position.z);
	VECTOR yZeroObstruct = VGet(enemy.GetPosition().x, 0, enemy.GetPosition().z);

	VECTOR obsToPlayer = VSub(yZeroPlayer, yZeroObstruct);

	// �Ԃ������Ƃ��ɗ��������B���傤�ǂ���float�덷�ŏd�Ȃ葱����̂ŏ����Ԃ�������.
	float awayRange = (m_hitRadius + enemy.GetRadius() + 0.01f);

	VECTOR awayVec = VScale(VNorm(obsToPlayer), awayRange);
	m_position = VAdd(yZeroObstruct, awayVec);

}

// �G�l�~�[�Փˎ��A���̓����蔻�菈�����s����܂ł̃C���^�[�o��
void Player::HitInterval()
{
	if (m_hitEnemy == true)
	{
		// 1.5�b��ɃC���^�[�o������
		if (GetNowCount() - m_hitTime >= 2000)
		{
			m_hitTime = 0.0f;
		}

		// �C���^�[�o�������������ꂽ�瓖���蔻��t���O����������
		if (m_hitTime == 0.0f)
		{
			m_hitEnemy = false;
		}
	}
}
