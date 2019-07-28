#include "Item.h"

const float Item::FALL_SPEED = 50.0f;

// �R���X�g���N�^
Item::Item(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	// �����Ȃ�
}

// �f�X�g���N�^
Item::~Item()
{
	// �����Ȃ�
}

// �e�평��������
void Item::Initialize()
{
	// ���a��ݒ�
	m_radius = 3.0f;
	// ��Ԃ��A�N�e�B�u��
	m_state = Item::POP;
}

// �X�V����
void Item::Update()
{
	// �|�W�V������ݒ�
	MV1SetPosition(m_modelHandle, m_position);
}

// �o������������
void Item::Fall(float deltaTime)
{
	// �󒆂ɂ��鎞�ɗ���
	if (m_position.y >= 1.0f)
	{
		m_position.y -= FALL_SPEED * deltaTime;
	}

	// ���W�����l�ȉ��ŃA�N�e�B�u��
	if (m_position.y <= 1.0f)
	{
		m_state = Item::ACTIVE;
	}
}

// �`�揈��
void Item::Draw()
{
	// ���f����`��
	MV1DrawModel(m_modelHandle);
	// �����蔻��m�F�p�̋�
	DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

