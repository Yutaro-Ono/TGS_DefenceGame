
#include "ObjectPod.h"

const VECTOR ObjectPod::INITIAL_POSITION = VGet(0.0f, 0.0f, 0.0f);         // �J�n���̏����ʒu
const float ObjectPod::HIT_RADIUS = 8.5f;                                  // �����蔻��p���a
const VECTOR ObjectPod::SCALE_SIZE = VGet(5.0f, 5.0f, 5.0f);               // �g�嗦�̃T�C�Y

// �R���X�g���N�^
ObjectPod::ObjectPod(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{

}

// �f�X�g���N�^
ObjectPod::~ObjectPod()
{
}

// �e�평��������
void ObjectPod::Initialize()
{
	m_position = INITIAL_POSITION;
	m_radius = HIT_RADIUS;

}

// �������
void ObjectPod::Delete()
{
}

// �X�V����
void ObjectPod::Update()
{
	// ���f���̊g�嗦�Z�b�g
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	// ���f���̍��W�Z�b�g
	MV1SetPosition(m_modelHandle, m_position);
}
