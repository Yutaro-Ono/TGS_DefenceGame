//-----------------------------------------------------------+
// �G�l�~�[�N���X
//      : �G�l�~�[�̌ŗL����
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "Math.h"
#include "Actor.h"
#include "PlayerManager.h"

// �N���X�O���錾
class PlayerManager;

class Enemy : public Actor
{

public:

	// ��Ԓ�`
	enum STATE
	{
		NONE = 0,
		ACTIVE,
		DEAD,
	};

	Enemy(int sourceModelHandle);                                             // �R���X�g���N�^
	~Enemy();                                                                 // �f�X�g���N�^

	void Initialize() override;                                               // �e�평��������
	void Delete()override {};                                                 // �������

	void Update(float deltaTime)override;                                     // �X�V����
	void Draw()override;                                                      // �`�揈��

	void SetEmergence(const VECTOR popPos);                                   // �ŏ��̏o���ʒu�ݒ�

	void OnHitOtherEnemy(Enemy& other_enemy);                                 // ���G�l�~�[�Ɠ����������̏���

	void ChaseTarget(PlayerManager& playerManager, float deltaTime);          // �^�[�Q�b�g(�v���C���[)�̒ǐՏ���
	void HitInterval();                                                       // �v���C���[�ƏՓˎ��A���̓����蔻�肪�s����܂ł̃C���^�[�o���v���֐�

	//-------------------------------------------------------------+
	// Getter/Setter�֘A
	//-------------------------------------------------------------+
	// �v���C���[�Ƃ̏Փ˃t���O���擾����
	const bool& GetHitPlayer()const { return m_hitPlayer; }
	// �G�l�~�[�̔��a���擾����
	const float& GetRadius()const { return m_hitRadius; }

	// �v���C���[�ƏՓ˂��Ă��邩�ǂ����̃Z�b�^�[
	void SetHitPlayer(bool p_hit) { m_hitPlayer = p_hit; }
	// �C���^�[�o���̃Z�b�^�[
	void SetInterval(const int count) { m_hitTime = count; }


private:

	VECTOR             m_targetVec;          // �^�[�Q�b�g(�v���C���[)�̃x�N�g��
	float              m_hitRadius;          // �����蔻��p���a
	bool               m_hitPlayer;          // �v���C���[�ɓ������Ă��邩�ǂ����̃t���O
	int                  m_hitTime;          // �v���C���[�ɓ������Ă��鎞�ɗp����C���^�[�o��


	static const VECTOR SCALE_SIZE;          // ���f���̊g�嗦
	static const float  MOVE_SPEED;          // �ړ����x

};