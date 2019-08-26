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
	// ��]�p�x�̏�����
	m_angleY = 0.0f;
	m_angleX = -45.0f;
	m_angleZ = 0.0f;
	// ���a��ݒ�
	m_radius = 3.0f;
	// ��Ԃ��A�N�e�B�u��
	m_state = Item::POP;
	// ���f���̉�]�p�x��ݒ�
	MV1SetRotationXYZ(m_modelHandle, VGet(m_angleX, m_angleY, m_angleZ));
}

// �X�V����
void Item::Update(float deltaTime)
{
	// �|�W�V������ݒ�
	MV1SetPosition(m_modelHandle, m_position);

	// ���f������]������
	MV1SetRotationXYZ(m_modelHandle, VGet(m_angleX, m_angleY, m_angleZ));

	// ��]�p�x���X�V
	m_angleY += 1.0f * deltaTime;
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

