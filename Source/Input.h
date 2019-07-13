//-----------------------------------------------------------+
// キー入力関連クラス
//      : キーボードの押下状態を取得する
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"


class Input final
{
public:

	// キー押下状態の詳細
	enum KEY_STATE
	{
		STATE_OFF,
		STATE_PUSHDOWN,
		STATE_PRESSED,
		STATE_PULLUP
	};

	// シングルトン
	static Input& InputInstance()
	{
		static Input input;
		return input;
	}

	~Input();

	// キーチェッカー
	void KeyChecker();

	// キーのゲッター(簡易版)
	const int& GetKeyPad() const { return key; };

	// キーのゲッター
	char GetInput(int keyCode) { return m_key[keyCode]; }

private:

	Input();      // コンストラクタ


	char m_key[256];
	char m_keyState[2][256];

	BYTE m_nowKey;           // 今押したキー
	BYTE m_prevKey;          // 前に押したキー

	int key;      // キー入力情報格納

};

#define INPUT_INSTANCE Input::InputInstance()