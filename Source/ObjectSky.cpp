//-----------------------------------------------------------------------+
// �X�J�C�h�[���N���X                                   
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectSky.h"

const VECTOR ObjectSky::SCALE_SIZE = { 12.0f, 12.0f, 12.0f };
const VECTOR ObjectSky::ROTATE_RAD = { 15.0f * DX_PI_F / 180.0f, 0.0f, 0.0f };

ObjectSky::ObjectSky(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, -800.0f, -5000.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

ObjectSky::~ObjectSky()
{
}

void ObjectSky::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);                 // �X�P�[���̐ݒ�  �����̃��f�������܂�ɂ��傫�����邽�ߏk��
	MV1SetRotationXYZ(m_modelHandle, ROTATE_RAD);           // ��]�l�̐ݒ�
	MV1SetPosition(m_modelHandle, m_position);
}
