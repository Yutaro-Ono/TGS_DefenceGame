// �^�C�}�[�N���X

#pragma once
#include "DxLib.h"
#include "SceneInGame.h"

class Timer
{
public:

	// �V���O���g��
	static Timer& GetInstatnce()
	{
		static Timer timer;
		return timer;
	}

	~Timer();                 // �f�X�g���N�^

	void Initialize();        // �^�C�}�[�̏�����

	void Delete();            // �^�C�}�[�̍폜

	void Update();            // �^�C�}�[�̌v��

	void Draw();              // �^�C�}�[�̕`��

	const int& GetTimer() const { return m_countTimer; }     // �J�E���g�^�C�}�[�̃Q�b�^�[

	const int& GetPrevTimer() const { return m_prevTimer; }  // ��b�O�̃^�C�}�[�Q�b�^�[

private:

	Timer();

	int m_countTimer;       // �J�E���g�_�E���p�^�C�}�[

	int m_startTimer;       // �X�^�[�g���^�C�}�[

	int m_limitTime;        // ��������

	int m_prevTimer;         // �O�̃^�C�}�[

	

	static const int LIMIT_TIME;     // 1�Q�[���̐�������
};

#define TIMER_INSTANCE Timer::GetInstatnce()