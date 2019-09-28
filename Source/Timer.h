//-----------------------------------------------------------+
// �^�C�}�[�N���X
//      : �������ԏ����Ȃǂɗp����^�C�}�[
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "SceneInGame.h"
#include "TextGraph.h"

// �N���X�O���錾
class TextGraph;

class Timer
{

public:

	Timer();                                                         // �R���X�g���N�^
	~Timer();                                                        // �f�X�g���N�^

	void Initialize();                                               // �^�C�}�[�̏�����

	void Delete();                                                   // �^�C�}�[�̍폜

	void CountUp();                                                  // �^�C�}�[�̌v��(�J�E���g�A�b�v��)

	void UpdateCountDown(const int in_maxTime);                      // �^�C�}�[�̌v��(�J�E���g�_�E��)

	void Draw(TextGraph& text);                                      // �^�C�}�[�̕`��

	const int& GetTimer() const { return m_countTimer; }             // �J�E���g�^�C�}�[�̃Q�b�^�[

	const int& GetLimitTime() const { return m_limitTime; }          // �������Ԃ̃Q�b�^�[

	const int& GetPrevTimer() const { return m_prevTimer; }          // ��b�O�̃^�C�}�[�Q�b�^�[

	const int& RunTimer(const int in_limit);


private:

	bool m_isInsert;           // �������Ԃ��Z�b�g�������ǂ���

	int m_countTimer;          // �J�E���g�_�E���p�^�C�}�[

	int m_startTimer;          // �X�^�[�g���^�C�}�[

	int m_limitTime;           // ��������

	int m_prevTimer;           // �O�̃^�C�}�[

};
