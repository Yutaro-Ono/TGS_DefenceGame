//-----------------------------------------------------------+
// �����Ȃ��ǃN���X
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "ObjectVisibleWall.h"

// �R���X�g���N�^
ObjectVisibleWall::ObjectVisibleWall()
{
	// �����Ȃ�
}

// �f�X�g���N�^
ObjectVisibleWall::~ObjectVisibleWall()
{
	// �����Ȃ�
}

// �X�V����
void ObjectVisibleWall::Update(float deltaTime)
{
	// �����蔻��m�F�p�̋�
	DrawSphere3D(m_position, 3.0f, 5, 0x00ffff, 0x00ffff, FALSE);
}
