//-----------------------------------------------------------------------+
// �X�J�C�h�[���N���X                                   
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "ObjectSky.h"

const VECTOR ObjectSky::SCALE_SIZE = { 12.0f, 12.0f, 12.0f };
const VECTOR ObjectSky::ROTATE_RAD = { 15.0f * DX_PI_F / 180.0f, 0.0f, 0.0f };

// �R���X�g���N�^
ObjectSky::ObjectSky(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, -800.0f, -5000.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

// �f�X�g���N�^
ObjectSky::~ObjectSky()
{
	// �����Ȃ�
}

// ����������
void ObjectSky::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);                 // �X�P�[���̐ݒ�  �����̃��f�������܂�ɂ��傫�����邽�ߏk��
	MV1SetRotationXYZ(m_modelHandle, ROTATE_RAD);           // ��]�l�̐ݒ�
	MV1SetPosition(m_modelHandle, m_position);
}

// �X�V����
void ObjectSky::Update(float deltaTime)
{
	// ���f������]������
	MV1SetRotationXYZ(m_modelHandle, VGet(m_direction.x, m_direction.y, m_direction.z));

	// ��]�p�x���X�V
	m_direction.y -= 0.01f * deltaTime;
}
