//-----------------------------------------------------------+
// �L�[���͊֘A�N���X
//      : �L�[�{�[�h�̉�����Ԃ��擾����
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"


class Input final
{
public:

	// �L�[������Ԃ̏ڍ�
	enum KEY_STATE
	{
		STATE_OFF,
		STATE_PUSHDOWN,
		STATE_PRESSED,
		STATE_PULLUP
	};

	// �V���O���g��
	static Input& InputInstance()
	{
		static Input input;
		return input;
	}

	~Input();

	// �L�[�`�F�b�J�[
	void KeyChecker();

	// �L�[�̃Q�b�^�[(�ȈՔ�)
	const int& GetKeyPad() const { return key; };

	// �L�[�̃Q�b�^�[
	char GetInput(int keyCode) { return m_key[keyCode]; }

private:

	Input();      // �R���X�g���N�^


	char m_key[256];
	char m_keyState[2][256];

	BYTE m_nowKey;           // ���������L�[
	BYTE m_prevKey;          // �O�ɉ������L�[

	int key;      // �L�[���͏��i�[

};

#define INPUT_INSTANCE Input::InputInstance()