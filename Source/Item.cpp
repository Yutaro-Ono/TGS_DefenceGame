#include "Item.h"

const float Item::FALL_SPEED = 50.0f;

// �R���X�g���N�^
Item::Item(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
	,m_hitRadius(3.0f)
{
	
}

// �f�X�g���N�^
Item::~Item()
{
}

// �e�평��������
void Item::Initialize()
{
	// ��Ԃ��A�N�e�B�u��
	m_state = Item::POP;

}

// �X�V����
void Item::Update()
{
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
	MV1DrawModel(m_modelHandle);
	// �����蔻��m�F�p�̋�
	DrawSphere3D(m_position, m_hitRadius, 5, 0x00ffff, 0x00ffff, FALSE);
}

