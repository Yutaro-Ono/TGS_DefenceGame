#include "Item.h"

const float Item::FALL_SPEED = 100.0f;

// �R���X�g���N�^
Item::Item(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
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
	m_state = (int)Item::POP;

	
}

// �X�V����
void Item::Update()
{

}

// �o������������
void Item::Fall(float deltaTime)
{
	// �󒆂ɂ��鎞�ɗ���
	if (m_position.y < 0)
	{
		m_position.y += FALL_SPEED * deltaTime;
	}

}

// �`�揈��
void Item::Draw()
{
}
