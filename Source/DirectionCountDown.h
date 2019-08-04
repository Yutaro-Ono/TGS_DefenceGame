//--------------------------------------------------------------+
// �J�E���g�_�E���n�̉��o�����N���X
//      : �Q�[���J�n���A�C���^�[�o�����̃J�E���g�_�E�����o����
//                                  Last Update : 2019/08/04
//--------------------------------------------------------------+
#pragma once
#include "DirectionBase.h"
#include "Timer.h"

class CountDown : public DirectionBase
{
public:

	CountDown();
	~CountDown();

	void Initialize() override;

	void StartCountDown();

private:

	int m_prevTick;              // �O��̍X�V����
	int m_nowTick;               // ���݂̍X�V����

	Timer* m_timer;              // �^�C�}�[�N���X
};