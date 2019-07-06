#include "ObjectVisibleWall.h"

ObjectVisibleWall::ObjectVisibleWall()
{
}

ObjectVisibleWall::~ObjectVisibleWall()
{
}

void ObjectVisibleWall::Update()
{
	// “–‚½‚è”»’èŠm”F—p‚Ì‹…
	DrawSphere3D(m_position, 3.0f, 5, 0x00ffff, 0x00ffff, FALSE);
}
