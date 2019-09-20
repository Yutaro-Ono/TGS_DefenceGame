//-----------------------------------------------------------------------+
// �A�C�h��(��q�Ώ�)�N���X                            
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "Idol.h"

const VECTOR Idol::SCALE_SIZE = { 1.0f, 1.0f, 1.0f };

// �R���X�g���N�^
Idol::Idol(int sourceModelHandle)
	:Actor(sourceModelHandle)
{
	m_position = VGet(0.0f, 0.0f, 0.0f);
}

// ����������
void Idol::Initialize()
{
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	MV1SetPosition(m_modelHandle, m_position);
}

// �������
void Idol::Delete()
{
}

// �X�V����
void Idol::Update(float deltaTime)
{
}

// �`�揈��
void Idol::Draw()
{
}
