#include "ObjectVisibleWall.h"

ObjectVisibleWall::ObjectVisibleWall()
{
}

ObjectVisibleWall::~ObjectVisibleWall()
{
}

void ObjectVisibleWall::Update(float deltaTime)
{
	// 当たり判定確認用の球
	DrawSphere3D(m_position, 3.0f, 5, 0x00ffff, 0x00ffff, FALSE);
}
