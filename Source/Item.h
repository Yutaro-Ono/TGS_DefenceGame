//-----------------------------------------------------------+
// �A�C�e���N���X
//      : �A�C�e��
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "ObjectBase.h"

class Item : public ObjectBase
{
public:

	enum STATE_ITEM
	{
		NONE,
		POP,
		ACTIVE,
		DEACTIVE,
		DEAD
	};

	Item(int sourceModelHandle);           // �R���X�g���N�^
	~Item();                               // �f�X�g���N�^

	void Initialize();                     // �e�평��������

	void Update(float deltaTime);          // �X�V����

	void Fall(float deltaTime);            // �o�����̗�������

	void Draw();                           // �`�揈��

	//-------------------------------------------------------------+
    // Getter/Setter�֘A
    //-------------------------------------------------------------+
	// ��Ԃ̃Q�b�^�[
	const int& GetState() const { return m_state; }

	// �|�W�V�����̃Z�b�^�[
	void SetEmergence(const VECTOR popPos) { m_position = popPos; }
	// Deactive(����)��Ԃւ̃Z�b�^�[
	void SetDeactive() { m_state = Item::DEACTIVE; }


private:

	float             m_hitRadius;          // �����蔻��p�̔��a

	int                   m_state;               // �Q�[�����̏��


	static const float FALL_SPEED;       // �������x
};