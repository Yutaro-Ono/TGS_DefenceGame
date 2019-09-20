//-----------------------------------------------------------------------+
// �L�[���͊֘A�N���X                      
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// �C���N���[�h�t�@�C��
#include "Input.h"

const int Input::LSTICK_DEADZONE = 10000;

// �R���X�g���N�^
Input::Input()
{
	m_nowKey = 0;
	m_prevKey = 0;

	// ������
	for (int i = 0; i < 256; i++)
	{
		m_key[i] = 0;
		m_keyState[m_nowKey][i] = STATE_OFF;
	}

	for (int i = 0; i < XINPUT_BUTTON::XINPUT_ALL; i++)
	{
		m_nowButton[i] = 0;
		m_prevButton[i] = 0;
	}
}

// �f�X�g���N�^
Input::~Input()
{
	// �����Ȃ�
}

// �p�b�h(1P, 2P, 3P, 4P)���q����Ă��邩
bool Input::ScanPadNum(const PAD_NUM in_padNum)
{
	switch (in_padNum)
	{
	case PAD_NUM::PLAYER_1:
		GetJoypadXInputState(DX_INPUT_PAD1, &m_xInput);
		return true;

	case PAD_NUM::PLAYER_2:
		GetJoypadXInputState(DX_INPUT_PAD2, &m_xInput);
		return true;

	case PAD_NUM::PLAYER_3:
		GetJoypadXInputState(DX_INPUT_PAD3, &m_xInput);
		return true;

	case PAD_NUM::PLAYER_4:
		GetJoypadXInputState(DX_INPUT_PAD4, &m_xInput);
		return true;
	}
	return false;
}

// �Q�[���p�b�h(xinput)�̃{�^��������Ԃ��擾
bool Input::GetPushButtonState(const XINPUT_BUTTON in_padButton)
{
	switch (in_padButton)
	{
	case XINPUT_BUTTON::XINPUT_A:
		if (m_xInput.Buttons[XINPUT_BUTTON_A]) { return true; }
		return false;

	case XINPUT_BUTTON::XINPUT_B:
		if (m_xInput.Buttons[XINPUT_BUTTON_B]) { return true; }
		return false;

	case XINPUT_BUTTON::XINPUT_X:
		if (m_xInput.Buttons[XINPUT_BUTTON_X]) { return true; }
		return false;

	case XINPUT_BUTTON::XINPUT_Y:
		if (m_xInput.Buttons[XINPUT_BUTTON_Y]) { return true; }
		return false;

	case XINPUT_BUTTON::XINPUT_START:
		if (m_xInput.Buttons[XINPUT_BUTTON_START]) { return true; }
		return false;

	case XINPUT_BUTTON::XINPUT_BACK:
		if (m_xInput.Buttons[XINPUT_BUTTON_BACK]) { return true; }
		return false;

	}

	return false;
}

bool Input::ScanPushButton(const int in_pushButton, const int in_num)
{
	if (m_xInput.Buttons[in_pushButton])
	{
		return true;
	}

	return false;
}

// ���X�e�B�b�N���͂̃Q�b�^�[
bool Input::GetLeftStickState(const XINPUT_LSTICK in_stickDir)
{
	switch (in_stickDir)
	{
	case XINPUT_LSTICK::LSTICK_LEFT:
		if (m_xInput.ThumbLX <= -LSTICK_DEADZONE) { return true; }
		return false;

	case XINPUT_LSTICK::LSTICK_RIGHT:
		if (m_xInput.ThumbLX >= LSTICK_DEADZONE) { return true; }
		return false;

	case XINPUT_LSTICK::LSTICK_UP:
		if (m_xInput.ThumbLY >= LSTICK_DEADZONE) { return true; }
		return false;

	case XINPUT_LSTICK::LSTICK_DOWN:
		if (m_xInput.ThumbLY <= -LSTICK_DEADZONE) { return true; }
		return false;
	}

	return false;
}

void Input::KeyChecker()
{
	// ���݂̃L�[�ƑO�̃L�[��Ԃ̓���ւ�
	m_nowKey ^= 1;
	m_prevKey = m_nowKey ^ 1;

	// �L�[��Ԃ̎擾
	GetHitKeyStateAll(m_keyState[m_nowKey]);

	for (int i = 0; i < 256; i++)
	{
		char m_nowInput = m_keyState[m_nowKey][i];
		char m_prevInput = m_keyState[m_prevKey][i];

		// ���݉�����Ă����
		if (m_nowInput)
		{
			// �O�̃t���[���ł�������Ă����Ȃ��
			if (m_prevInput)
			{
				m_key[i] = STATE_PRESSED;       // �p���I�ȉ������
			}
			else
			{
				m_key[i] = STATE_PUSHDOWN;      // �������ꂽ
			}
		}
		else
		{
			// �L�[��������Ă��Ȃ����

			if (m_prevInput)
			{
				m_key[i] = STATE_PULLUP;      // �{�^���𗣂���
			}
			else
			{
				m_key[i] = STATE_OFF;         // �{�^���͉�����Ă��Ȃ�
			}
		}
	}

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}
