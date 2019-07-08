//-----------------------------------------------------------+
// �v���C���[�N���X
//      : �v���C���[�̌ŗL���� (�A�N�^�[�N���X���p��)
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Input.h"
#include "Enemy.h"

class Enemy;

class Player : public Actor
{
public:
	Player(const int sourceModelHandle);                         // �R���X�g���N�^
	~Player();                                                   // �f�X�g���N�^

	void Initialize() override {};

	void Delete() override {};

	void Update(float deltaTime) override;                       // �v���C���[�֘A�̍X�V

	void Draw()override;                                         // �v���C���[�̕`��

	void MotionMove(float deltaTime);                            // �ړ��̃��[�V����

	// �����蔻��֘A�̏���
	const float& GetRadius()const { return m_hitRadius; }        // �����蔻�蔼�a�̃Q�b�^�[
	void OnHitEnemy(Enemy& enemy);                               // �G�l�~�[�Ƃ̓����蔻�菈��

private:

	VECTOR m_velocity;                        // �����x

	float velocityY;                          // ����������x

	float m_hitRadius;                        // �����蔻��p���a

	static const float MOVE_SPEED;            // �v���C���[�̈ړ����x

	static const float INITIAL_POSITION_Y;    // Player�̃v���C���[��Y���W

	static const VECTOR SCALE_SIZE;           // �g�嗦�̃T�C�Y

	bool m_moveFlag;                          // �ړ����Ă��邩�ǂ����̃t���O
	static const float JUMP_POWER;            // �ړ����[�V�����ɂ����鏬���݃W�����v�̏�����p���[
	static const float JUMP_SUB;              // �ړ����[�V�����ɂ����鏬���݃W�����v�̌��Z�����ɗp����
	
};

