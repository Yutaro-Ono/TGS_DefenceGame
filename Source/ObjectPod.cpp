//-----------------------------------------------------------------------+
// ����|�b�h�N���X                 
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#include "ObjectPod.h"

const VECTOR ObjectPod::INITIAL_POSITION = VGet(0.0f, 0.0f, 0.0f);         // �J�n���̏����ʒu
const float ObjectPod::HIT_RADIUS = 8.5f;                                  // �����蔻��p���a
const VECTOR ObjectPod::SCALE_SIZE = VGet(5.0f, 5.0f, 5.0f);               // �g�嗦�̃T�C�Y

// �R���X�g���N�^
ObjectPod::ObjectPod(int sourceModelHandle)
	:ObjectBase(sourceModelHandle)
{
	// �����Ȃ�
}

// �f�X�g���N�^
ObjectPod::~ObjectPod()
{
	// �����Ȃ�
}

// �e�평��������
void ObjectPod::Initialize()
{
	m_position = INITIAL_POSITION;
	m_radius = HIT_RADIUS;
	m_effect = new PlayEffect("Data/Effects/ItemPod_PodEffect.efk");
	m_effect->Initialize();
}

// �������
void ObjectPod::Delete()
{
	m_effect->Delete();

	delete (m_effect);
}

// �X�V����
void ObjectPod::Update(float deltaTime)
{
	// ���f���̊g�嗦�Z�b�g
	MV1SetScale(m_modelHandle, SCALE_SIZE);
	// ���f���̍��W�Z�b�g
	MV1SetPosition(m_modelHandle, m_position);

	// �|�b�h�G�t�F�N�g�̍Đ�
	if (m_effect->GetNowPlaying() == -1)
	{
		m_effect->PlayEffekseer(GetPosition());
		m_effect->SetEffectScale(12.0f, 12.0f, 12.0f);
	}

}
