//-----------------------------------------------------------------------+
// �t�B�[���h�I�u�W�F�N�g�N���X                                 
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectField.h"

const VECTOR ObjectField::SCALE_SIZE = { 20.0f, 5.0f, 18.0f };      // ���f���̊g�嗦

// �R���X�g���N�^
ObjectField::ObjectField(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, -10.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

// �f�X�g���N�^
ObjectField::~ObjectField()
{
	// �����Ȃ�
}

// ����������
void ObjectField::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);
}

// �X�V����
void ObjectField::Update(float deltaTime)
{
	// �����Ȃ�
}
