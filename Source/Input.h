//-----------------------------------------------------------+
// �L�[���͊֘A�N���X
//      : �L�[�{�[�h�̉�����Ԃ��擾����
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"

enum PAD_NUM
{
	PLAYER_1,
	PLAYER_2,
	PLAYER_3,
	PLAYER_4,
};

enum XINPUT_BUTTON
{
	XINPUT_A,
	XINPUT_B,
	XINPUT_X,
	XINPUT_Y,
	XINPUT_START,
	XINPUT_BACK,
	XINPUT_ALL,
};

enum XINPUT_TRIGGER
{
	XINPUT_R,
	XINPUT_RB,
	XINPUT_L,
	XINPUT_LB,
};

enum XINPUT_LSTICK
{
	LSTICK_LEFT,
	LSTICK_RIGHT,
	LSTICK_UP,
	LSTICK_DOWN,
};

class Input final
{
public:

	Input();
	~Input();

	// �L�[������Ԃ̏ڍ�
	enum KEY_STATE
	{
		STATE_OFF,
		STATE_PUSHDOWN,
		STATE_PRESSED,
		STATE_PULLUP
	};

	// �p�b�h�̔ԍ����擾(1P, 2P, 3P, 4P)
	bool ScanPadNum(const PAD_NUM in_padNum);
	// �Q�[���p�b�h(xinput)�̃{�^��������Ԃ��擾
	bool GetPushButtonState(const XINPUT_BUTTON in_padButton);
	// �{�^���̉�����Ԃ��X�L����
	bool ScanPushButton(const int in_pushButton, const int in_num);
	// ���X�e�B�b�N���͂̃Q�b�^�[
	bool GetLeftStickState(const XINPUT_LSTICK in_stickDir);

	// �L�[�`�F�b�J�[
	void KeyChecker();

	// �L�[�̃Q�b�^�[(�ȈՔ�)
	const int& GetKeyPad() const { return key; };

	// �L�[�̃Q�b�^�[
	char GetInput(int keyCode) { return m_key[keyCode]; }

private:

	XINPUT_STATE m_xInput;

	int m_nowButton[XINPUT_BUTTON::XINPUT_ALL];
	int m_prevButton[XINPUT_BUTTON::XINPUT_ALL];

	char m_key[256];
	char m_keyState[2][256];

	BYTE m_nowKey;           // ���������L�[
	BYTE m_prevKey;          // �O�ɉ������L�[

	int key;      // �L�[���͏��i�[

	static const int LSTICK_DEADZONE;
};