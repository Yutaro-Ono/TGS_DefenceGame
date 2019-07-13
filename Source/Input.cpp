//-----------------------------------------------------------------------+
// �L�[���͊֘A�N���X                      
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Input.h"

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
}

Input::~Input()
{
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
