//-----------------------------------------------------------------------+
// �A�N�^�[���N���X                                   
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "Actor.h"

Actor::Actor(const int sourceModelHandle)
	:m_modelHandle(-1)
{
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);     // ���f���𕡐�

	printfDx("���f�������[�h\n");

}

Actor::~Actor()
{
	MV1DeleteModel(m_modelHandle);      // ���f�����폜
}

// ���f���̕`��
void Actor::Draw()
{

	MV1DrawModel(m_modelHandle);


	printfDx("���f����`��\n");
}
