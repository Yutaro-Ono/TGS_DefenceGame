//-----------------------------------------------------------+
// �v���C���[�N���X
//      : �v���C���[�̌ŗL���� (�A�N�^�[�N���X���p��)
//                                  Last Update : 2019/07/13
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

	void Initialize() override {};                               // ����������

	void Delete() override {};                                   // �e��������

	void Update(float deltaTime) override;                       // �v���C���[�֘A�̍X�V

	void Draw()override;                                         // �v���C���[�̕`��

	void HitWallUpdate(float deltaTime);                         // �ȈՓI�ȃt�B�[���h�̓����蔻��

	void MotionMove(float deltaTime);                            // �ړ��̃��[�V����

	void OnHitEnemy(Enemy& enemy);                               // �G�l�~�[�Ƃ̓����蔻�菈��
	void HitInterval();                                          // �G�l�~�[�Փˎ��A���̓����蔻�菈�����s����܂ł̃C���^�[�o��

	//--------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------+
	const float& GetRadius()const { return m_hitRadius; }        // �����蔻�蔼�a�̃Q�b�^�[
	const bool& GetHitEnemy() const { return m_hitEnemy; }       // �G�l�~�[�Ɠ����������ǂ����̃Q�b�^�[
	const int& GetHitPoint() const { return m_hitPoint; }        // �v���C���[�̗͂̃Q�b�^�[

	void SetHitEnemy(bool hit_e) { m_hitEnemy = hit_e; }         // �G�l�~�[�Ƃ̓����蔻��t���O�̃Z�b�^�[
	void SetInterval(const int count) { m_hitTime = count; }     // �C���^�[�o���̃Z�b�^�[
	void SetDamaged() { m_hitPoint -= 1; }                       // �G�l�~�[�Փˎ��A�̗͌��Z����



private:

	int m_hitPoint;                                              // �v���C���[�̗�

	VECTOR m_velocity;                                           // �����x

	float velocityY;                                             // ����������x

	float m_hitRadius;                                           // �����蔻��p���a
	bool m_hitEnemy;                                             // �G�l�~�[�ɓ����������ǂ����̃t���O

	int m_hitTime;                                               // �����蔻�肪�A���Ŕ�������܂ł̃C���^�[�o��

	static const float MOVE_SPEED;                               // �v���C���[�̈ړ����x

	static const float INITIAL_POSITION_Y;                       // Player�̃v���C���[��Y���W

	static const VECTOR SCALE_SIZE;                              // �g�嗦�̃T�C�Y

	bool m_moveFlag;                                             // �ړ����Ă��邩�ǂ����̃t���O

	static const int MAX_HP;                                     // �̗͂̍ő�l
	static const float JUMP_POWER;                               // �ړ����[�V�����ɂ����鏬���݃W�����v�̏�����p���[
	static const float JUMP_SUB;                                 // �ړ����[�V�����ɂ����鏬���݃W�����v�̌��Z�����ɗp����
	
};

