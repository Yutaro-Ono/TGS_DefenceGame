//-----------------------------------------------------------------------+
// �t�B�[���h�I�u�W�F�N�g�N���X                                 
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "ObjectField.h"

//const VECTOR ObjectField::SCALE_SIZE = { 1.8f, 1.5f, 1.8f };      // ���f���̊g�嗦
const VECTOR ObjectField::SCALE_SIZE = { 0.25f, 0.3f, 0.19f };      // ���f���̊g�嗦

ObjectField::ObjectField(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
	m_direction = VGet(0.0f, 0.0f, 0.0f);
	m_radius = 0.0f;
}

ObjectField::~ObjectField()
{
}

void ObjectField::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);

	// �Q�|���S�����̒��_�̃f�[�^���Z�b�g
				// ��ʂ̒����ɕ��E����100�ŕ`��
	m_vertex[0].pos.x = 0.0F - 50.0F;    m_vertex[0].pos.y = 0.0F + 5.0F;    m_vertex[0].pos.z = 50.0f;
	m_vertex[0].u = 0.0F;
	m_vertex[0].v = 0.0F;

	m_vertex[1].pos.x = 0.0F + 50.0F;    m_vertex[1].pos.y = 0.0F + 5.0F;    m_vertex[1].pos.z = -50.0f;
	m_vertex[1].u = 1.0F;
	m_vertex[1].v = 0.0F;

	m_vertex[2].pos.x = 0.0F - 50.0F;    m_vertex[2].pos.y = 0.0F - 5.0F;    m_vertex[2].pos.z = 50.0f;
	m_vertex[2].u = 0.0F;
	m_vertex[2].v = 1.0F;

	m_vertex[3].pos.x = 0.0F + 50.0F;    m_vertex[3].pos.y = 0.0F - 5.0F;    m_vertex[3].pos.z = -50.0f;
	m_vertex[3].u = 1.0F;
	m_vertex[3].v = 1.0F;

	m_vertex[4].pos.x = 0.0F - 50.0F;    m_vertex[4].pos.y = 0.0F - 5.0F;    m_vertex[4].pos.z = 50.0f;
	m_vertex[4].u = 0.0F;
	m_vertex[4].v = 1.0F;

	m_vertex[5].pos.x = 0.0F + 50.0F;    m_vertex[5].pos.y = 0.0F + 5.0F;    m_vertex[5].pos.z = -50.0f;
	m_vertex[5].u = 1.0F;
	m_vertex[5].v = 0.0F;

	//// �P�x�͑S�v�f100%
	//m_vertex[0].r = m_vertex[0].g = m_vertex[0].b = 255;
	//m_vertex[1].r = m_vertex[1].g = m_vertex[1].b = 255;
	//m_vertex[2].r = m_vertex[2].g = m_vertex[2].b = 255;
	//m_vertex[3].r = m_vertex[3].g = m_vertex[3].b = 255;
	//m_vertex[4].r = m_vertex[4].g = m_vertex[4].b = 255;
	//m_vertex[5].r = m_vertex[5].g = m_vertex[5].b = 255;

	//// a ���ő�l
	//m_vertex[0].a = 255;
	//m_vertex[1].a = 255;
	//m_vertex[2].a = 255;
	//m_vertex[3].a = 255;
	//m_vertex[4].a = 255;
	//m_vertex[5].a = 255;

}

void ObjectField::Update()
{
	// �Q�|���S���̕`��
	// DrawPolygon3D(m_vertex, 2, DX_NONE_GRAPH, FALSE);
}
