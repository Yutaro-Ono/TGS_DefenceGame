#include "ObjectVisibleWall.h"

ObjectVisibleWall::ObjectVisibleWall()
{
}

ObjectVisibleWall::~ObjectVisibleWall()
{
}

void ObjectVisibleWall::Update()
{
	// �����蔻��m�F�p�̋�
	DrawSphere3D(m_position, 3.0f, 5, 0x00ffff, 0x00ffff, FALSE);
}
