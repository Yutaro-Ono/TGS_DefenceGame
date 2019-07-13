//-----------------------------------------------------------------------+
// キー入力関連クラス                      
//                                              Last Update : 2019/07/13
//-----------------------------------------------------------------------+
#include "Input.h"

Input::Input()
{
	m_nowKey = 0;
	m_prevKey = 0;

	// 初期化
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
	// 現在のキーと前のキー状態の入れ替え
	m_nowKey ^= 1;
	m_prevKey = m_nowKey ^ 1;

	// キー状態の取得
	GetHitKeyStateAll(m_keyState[m_nowKey]);

	for (int i = 0; i < 256; i++)
	{
		char m_nowInput = m_keyState[m_nowKey][i];
		char m_prevInput = m_keyState[m_prevKey][i];

		// 現在押されていれば
		if (m_nowInput)
		{
			// 前のフレームでも押されていたならば
			if (m_prevInput)
			{
				m_key[i] = STATE_PRESSED;       // 継続的な押下状態
			}
			else
			{
				m_key[i] = STATE_PUSHDOWN;      // 今押された
			}
		}
		else
		{
			// キーが押されていなければ

			if (m_prevInput)
			{
				m_key[i] = STATE_PULLUP;      // ボタンを離した
			}
			else
			{
				m_key[i] = STATE_OFF;         // ボタンは押されていない
			}
		}
	}

	key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}
