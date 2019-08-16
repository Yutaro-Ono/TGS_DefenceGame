//-----------------------------------------------------------+
// �v���C���[�N���X
//      : �v���C���[�̌ŗL���� (�A�N�^�[�N���X���p��)
//                                  Last Update : 2019/07/28
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

	void Initialize() override;                                  // ����������

	void Delete() override {};                                   // �e��������

	void Update(float deltaTime) override;                       // �v���C���[�֘A�̍X�V(�I�[�o�[���C�h)

	void Update(Input& input, float deltaTime);                  // �v���C���[�֘A�̍X�V

	void Draw()override;                                         // �v���C���[�̕`��

	void HitWallUpdate(float deltaTime);                         // �ȈՓI�ȃt�B�[���h�̓����蔻��

	void MotionMove(float deltaTime);                            // �ړ��̃��[�V����

	void OnHitEnemy(Enemy& enemy);                               // �G�l�~�[�Ƃ̓����蔻�菈��
	void HitInterval();                                          // �G�l�~�[�Փˎ��A���̓����蔻�菈�����s����܂ł̃C���^�[�o��

	//----------------------------------------------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//----------------------------------------------------------------------------------------------------------------+
	const float& GetRadius()const { return m_hitRadius; }                                 // �����蔻�蔼�a�̃Q�b�^�[
	const bool& GetHitEnemy() const { return m_hitEnemy; }                                // �G�l�~�[�Ɠ����������ǂ����̃Q�b�^�[
	const int& GetHitPoint() const { return m_hitPoint; }                                 // �v���C���[�̗͂̃Q�b�^�[
	// �A�C�e���֘A
	const int& GetHoldItem() const { return m_holdItemNum; }                              // �������Ă���A�C�e���̐���Ԃ�
	const int& GetMaxHold() const { return Player::MAX_HOLDITEM; }                        // �����ł���A�C�e���̍ő吔��Ԃ�
	void AddHoldItem() { m_holdItemNum++; };                                              // �������Ă���A�C�e���̐��𑝂₷
	void InitHoldItem() { m_holdItemNum = 0; }                                            // �A�C�e��������A�z�[���h�A�C�e���̃��Z�b�g�p
	// �X�R�A�֘A
	const bool& GetDeliveredItem() const { return m_deliverdItem; }                       // �A�C�e��������������ǂ����̃Q�b�^�[
	void SetDeliveredItem(bool in_delivered) { m_deliverdItem = in_delivered; }           // �A�C�e��������������ǂ����̃Z�b�^�[

	void SetHitEnemy(bool hit_e) { m_hitEnemy = hit_e; }                                  // �G�l�~�[�Ƃ̓����蔻��t���O�̃Z�b�^�[
	void SetInterval(const int count) { m_hitTime = count; }                              // �C���^�[�o���̃Z�b�^�[
	void SetDamaged() { m_hitPoint -= 1; }                                                // �G�l�~�[�Փˎ��A�̗͌��Z����



private:

	int m_hitPoint;                                              // �v���C���[�̗�

	VECTOR m_velocity;                                           // �����x

	float velocityY;                                             // ����������x

	bool m_moveFlag;                                             // �ړ����Ă��邩�ǂ����̃t���O

	int m_holdItemNum;                                           // ���ݏ������Ă���X�R�A�A�C�e���̐�(�X�R�A�A�C�e���ɏՓ˂ŉ��Z�A����n�_�ɂ����Ă����Ə��������X�R�A���Z)
	bool m_deliverdItem;                                         // �X�R�A������|�b�h�ɂ����Ă��������ǂ���

	float m_hitRadius;                                           // �����蔻��p���a
	bool m_hitEnemy;                                             // �G�l�~�[�ɓ����������ǂ����̃t���O
	int m_hitTime;                                               // �����蔻�肪�A���Ŕ�������܂ł̃C���^�[�o��

	static const float MOVE_SPEED;                               // �v���C���[�̈ړ����x
	static const float INITIAL_POSITION_Y;                       // Player�̃v���C���[��Y���W
	static const VECTOR SCALE_SIZE;                              // �g�嗦�̃T�C�Y
	static const int MAX_HP;                                     // �̗͂̍ő�l
	static const float JUMP_POWER;                               // �ړ����[�V�����ɂ����鏬���݃W�����v�̏�����p���[
	static const float JUMP_SUB;                                 // �ړ����[�V�����ɂ����鏬���݃W�����v�̌��Z�����ɗp����
	static const int MAX_HOLDITEM;                               // �A�C�e���̍ő及����
};

