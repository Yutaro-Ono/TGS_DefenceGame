// �^�C�}�[�N���X

#pragma once
#include "DxLib.h"
#include "SceneInGame.h"

class Timer final
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

private:

	Timer();

	int m_countTimer;

	int m_startTimer;

	int m_limitTime;

	static const int LIMIT_TIME;     // 1�Q�[���̐�������
};

#define TIMER_INSTANCE Timer::GetInstatnce()