//--------------------------------------------------------------+
// �J�E���g�_�E���n�̉��o�����N���X
//      : �Q�[���J�n���A�C���^�[�o�����̃J�E���g�_�E�����o����
//                                             2019 Yutaro Ono.
//--------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "DirectorBase.h"
#include "Timer.h"
#include "GameSystem.h"
#include "TextGraph.h"
#include "SoundFX.h"

// �N���X�O���錾
class Timer;
class TextGraph;
class SoundFX;

class CountDown : public DirectorBase
{

public:

	CountDown();                         // �R���X�g���N�^
	~CountDown();                        // �f�X�g���N�^

	void Initialize() override;          // �e�평��������

	void Delete() override;              // �e��������

	void Draw(TextGraph& text);          // �`�揈��

	bool StartCountDown();               // �Q�[���J�n���̃J�E���g�_�E�����o

	//--------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------+
	// �^�C�}�[�̒l�Ɋ�Â��摜�ԍ��̎擾
	const int& GetTimeGraphNum(const int in_nowTime) const;


private:

	int m_prevTime;                                                // �O��̍X�V����
	int m_nowTime;                                                 // ���݂̍X�V����

	int m_counterGraph[3];                                         // �J�E���g�_�E���̕`��p�O���t�B�b�N�n���h��

	bool m_playSE;                                                 // SE�Đ��̃t���O

	Timer* m_timer;                                                // �^�C�}�[�N���X
	SoundFX* m_sound;                                              // �T�E���h

	static const int MAX_START_TIME;                               // �J�n���̍ő�J�E���g�_�E������

};