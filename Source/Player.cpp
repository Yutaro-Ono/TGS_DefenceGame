//-----------------------------------------------------------------------+
// �v���C���[�N���X                        
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Player.h"

// �R���X�g���N�^(Actor�̏������q��t����)
Player::Player(const int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;

}

// �f�X�g���N�^�[
Player::~Player()
{
	// �����Ȃ�
}

// �X�V
void Player::Update()
{
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//-----------------------------------------//
	// �ړ�����
	//----------------------------------------//
	if (key & PAD_INPUT_UP)
	{
		m_position.z += 1.0f;
	}

	if (key & PAD_INPUT_DOWN)
	{
		m_position.z -= 1.0f;
	}

	if (key & PAD_INPUT_LEFT)
	{
		m_position.x -= 1.0f;
	}

	if (key & PAD_INPUT_RIGHT)
	{
		m_position.x += 1.0f;
	}

	// �|�W�V�������Z�b�g
	MV1SetPosition(m_modelHandle, m_position);

	//printfDx("pos : x = %f\ny = %f\nz = %f\n", m_position.x, m_position.y, m_position.z);
}
