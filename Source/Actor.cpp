//-----------------------------------------------------------------------+
// �A�N�^�[���N���X                                   
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "Actor.h"

// �R���X�g���N�^
Actor::Actor(const int sourceModelHandle)
	:m_modelHandle(-1)
{
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);          // ���f���𕡐�
}

// �f�X�g���N�^
Actor::~Actor()
{
	MV1DeleteModel(m_modelHandle);          // ���f�����폜
}

// ���f���̕`��
void Actor::Draw()
{
	// �����Ȃ�
}
