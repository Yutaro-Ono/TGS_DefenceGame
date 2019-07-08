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
	void Draw()override;

	void GazeTarget(PlayerManager& playerManager, float deltaTime);                               // �^�[�Q�b�g�̕����Ɉړ�

	const bool& GetHitPlayer()const { return m_hitPlayer; }                       // �v���C���[�ƏՓ˂��Ă��邩�ǂ����̃Q�b�^�[

	void SetEmergence(const VECTOR popPos);                                // �ŏ��̏o���ʒu�ݒ�
	void SetHitPlayer(bool p_hit) { m_hitPlayer = p_hit; }                 // �v���C���[�ƏՓ˂��Ă��邩�ǂ����̃Z�b�^�[
	void OnHitOtherEnemy(Enemy& other_enemy);                              // ���G�l�~�[�Ɠ����������̏���


	const float& GetRadius()const { return m_hitRadius; }

private:

	VECTOR m_targetVec;

	float m_hitRadius;

	bool m_hitPlayer;                                      // �v���C���[�ɓ������Ă��邩�ǂ����̃t���O

	static const VECTOR SCALE_SIZE;                        // �g�嗦
	static const float MOVE_SPEED;
};