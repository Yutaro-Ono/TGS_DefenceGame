//-----------------------------------------------------------+
// �G�l�~�[�N���X
//      : �G�l�~�[�̌ŗL����
//                                  Last Update : 2019/07/03
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:

	enum STATE
	{
		NONE = 0,
		ACTIVE,
		DEAD,
	};

	Enemy(int sourceModelHandle);                    // �R���X�g���N�^
	~Enemy();                                        // �f�X�g���N�^

	void Initialize() override;                      // �e�평��������

	void Emergence(const VECTOR popPos);             // �ŏ��̏o���ʒu�ݒ�

	void GazeTarget();                               // �^�[�Q�b�g�̕����Ɍ���
};