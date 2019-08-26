//--------------------------------------------------------------+
// �J�E���g�_�E���n�̉��o�����N���X
//      : �Q�[���J�n���A�C���^�[�o�����̃J�E���g�_�E�����o����
//                                  Last Update : 2019/08/04
//--------------------------------------------------------------+
#pragma once
#include "DirectorBase.h"
#include "Timer.h"
#include "GameSystem.h"

class Timer;

class CountDown : public DirectorBase
{
public:

	CountDown();
	~CountDown();

	void Initialize() override;       // �e�평��������

	void Delete() override;           // �e��������

	void Draw();                      // �`�揈��

	bool StartCountDown();            // �Q�[���J�n���̃J�E���g�_�E�����o

	const int& GetTimeGraphNum(const int in_nowTime) const;        // �^�C�}�[�Ɋ�Â��摜�ԍ��̃Q�b�^�[

private:

	int m_prevTime;              // �O��̍X�V����
	int m_nowTime;               // ���݂̍X�V����

	int m_counterGraph[3];       // �J�E���g�_�E���̕`��p�O���t�B�b�N�n���h��

	Timer* m_timer;              // �^�C�}�[�N���X

	static const int MAX_START_TIME;       // �J�n���̍ő�J�E���g�_�E������
};