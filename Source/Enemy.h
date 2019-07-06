//-----------------------------------------------------------+
// �G�l�~�[�N���X
//      : �G�l�~�[�̌ŗL����
//                                  Last Update : 2019/07/03
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Math.h"
#include "Actor.h"
#include "PlayerManager.h"

class PlayerManager;

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

	void Delete()override {};

	void Update(float deltaTime)override;

	void SetEmergence(const VECTOR popPos);             // �ŏ��̏o���ʒu�ݒ�

	void GazeTarget(PlayerManager& playerManager, float deltaTime);                               // �^�[�Q�b�g�̕����Ɍ���

private:

	VECTOR m_targetVec;



	static const VECTOR SCALE_SIZE;                        // �g�嗦
	static const float MOVE_SPEED;
};