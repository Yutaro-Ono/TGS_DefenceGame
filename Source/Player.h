//-----------------------------------------------------------+
// �v���C���[�N���X
//      : �v���C���[�̌ŗL���� (�A�N�^�[�N���X���p��)
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Input.h"

class Player : public Actor
{
public:
	Player(const int sourceModelHandle);   // �R���X�g���N�^
	~Player();                             // �f�X�g���N�^

	void Initialize() override {};

	void Delete() override {};

	void Update(float deltaTime) override;     // �v���C���[�֘A�̍X�V

	void MotionMove(float deltaTime);          // �ړ��̃��[�V����

private:

	VECTOR m_velocity;                     // �����x

	float velocityY;

	bool m_jumpFlag;                      // �W�����v�t���O

	static const float MOVE_SPEED;          // �v���C���[�̈ړ����x

	static const float INITIAL_POSITION_Y;    // Player�̃v���C���[��Y���W

	static const VECTOR SCALE_SIZE;        // �g�嗦�̃T�C�Y

	static const float JUMP_POWER;         // �ړ����[�V�����ɂ����鏬���݃W�����v�̏�����p���[
	static const float JUMP_SUB;           // �ړ����[�V�����ɂ����鏬���݃W�����v�̌��Z�����ɗp����
	
};

