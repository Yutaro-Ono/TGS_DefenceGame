//-----------------------------------------------------------------------+
// �v���C���[�N���X                        
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Player.h"

const float Player::MOVE_SPEED = 500.0f;
const float Player::INITIAL_POSITION_Y = 5.0f;
const VECTOR Player::SCALE_SIZE = { 0.05f, 0.05f, 0.05f };
const float Player::JUMP_POWER = 10.0f;
const float Player::JUMP_SUB = 0.3f;

// �R���X�g���N�^(Actor�̏������q��t����)
Player::Player(const int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_jumpFlag = false;
	m_position = VGet(0.0f, 5.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
	m_angle = 0.0f;
	velocityY = JUMP_POWER;
}

// �f�X�g���N�^�[
Player::~Player()
{
	// �����Ȃ�
}

// �X�V
void Player::Update(float deltaTime)
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//-----------------------------------------//
	// �ړ�����
	//----------------------------------------//
	if (key & PAD_INPUT_UP)
	{
		m_position.z += MOVE_SPEED * deltaTime;
		m_angle = 0.0f;
	}

	if (key & PAD_INPUT_DOWN)
	{
		m_position.z -= MOVE_SPEED * deltaTime;
		m_angle = -180.0f;
	}

	if (key & PAD_INPUT_LEFT)
	{
		m_position.x -= MOVE_SPEED * deltaTime;
		m_angle = -90.0f;
	}

	if (key & PAD_INPUT_RIGHT)
	{
		m_position.x += MOVE_SPEED * deltaTime;
		m_angle = 90.0f;
	}

	// �����ꂩ�̃L�[��������Ă��鎞
	if (key != 0)
	{
		if (m_jumpFlag == false)
		{
			m_jumpFlag = true;
		}
	}

	MotionMove(deltaTime);

	// ���f���̊g�嗦�Z�b�g
	MV1SetScale(m_modelHandle, SCALE_SIZE);

	// �p�x��ݒ�
	MV1SetRotationXYZ(m_modelHandle, VGet(0.0f, m_angle / 180.0f * DX_PI_F, 0.0f));

	// �|�W�V�������Z�b�g
	MV1SetPosition(m_modelHandle, m_position);

	//printfDx("pos : x = %f\ny = %f\nz = %f\n", m_position.x, m_position.y, m_position.z);
}

// �ړ����[�V�����ɂ����鏬���݂ȃW�����v���[�V����
void Player::MotionMove(float deltaTime)
{
	if (m_jumpFlag == true)
	{
		m_position.y = velocityY;
		velocityY -= JUMP_SUB;
		if (velocityY <= INITIAL_POSITION_Y)
		{
			m_jumpFlag = false;
		}
	}

	if (m_jumpFlag == false)
	{
		m_position.y = INITIAL_POSITION_Y;
		velocityY = JUMP_POWER;
	}

}
