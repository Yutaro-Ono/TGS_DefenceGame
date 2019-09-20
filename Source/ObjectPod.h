//-----------------------------------------------------------+
// ����|�b�h�N���X
//      : �A�C�e������p�̃|�b�h
//                                  Last Update : 2019/07/29
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "ObjectBase.h"
#include "Effect.h"

// �N���X�O���錾
class PlayEffect;

class ObjectPod : public ObjectBase
{

public:

	ObjectPod(int sourceModelHandle);               // �R���X�g���N�^
	~ObjectPod();                                   // �f�X�g���N�^

	void Initialize();                              // ����������
	void Delete();                                  // �������

	void Update(float deltaTime) override;          // �X�V����


private:

	PlayEffect*     m_effect;          // �|�b�h�̃G�t�F�N�g


	static const VECTOR           SCALE_SIZE;              // ���f���̊g�嗦�T�C�Y
	static const VECTOR     INITIAL_POSITION;              // �|�b�h�̏������W(�Œ�l)
	static const float            HIT_RADIUS;              // �����蔻��p�̔��a�̒萔

};