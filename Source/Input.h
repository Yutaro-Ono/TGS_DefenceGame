//-----------------------------------------------------------+
// キー入力関連クラス
//      : キーボードの押下状態を取得する
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

	// キー押下状態の詳細
	enum KEY_STATE
	{
		STATE_OFF,
		STATE_PUSHDOWN,
		STATE_PRESSED,
		STATE_PULLUP
	};

	// パッドの番号を取得(1P, 2P, 3P, 4P)
	bool ScanPadNum(const PAD_NUM in_padNum);
	// ゲームパッド(xinput)のボタン押下状態を取得
	bool GetPushButtonState(const XINPUT_BUTTON in_padButton);
	// ボタンの押下状態をスキャン
	bool ScanPushButton(const int in_pushButton, const int in_num);
	// 左スティック入力のゲッター
	bool GetLeftStickState(const XINPUT_LSTICK in_stickDir);

	// キーチェッカー
	void KeyChecker();

	// キーのゲッター(簡易版)
	const int& GetKeyPad() const { return key; };

	// キーのゲッター
	char GetInput(int keyCode) { return m_key[keyCode]; }

private:

	XINPUT_STATE m_xInput;

	int m_nowButton[XINPUT_BUTTON::XINPUT_ALL];
	int m_prevButton[XINPUT_BUTTON::XINPUT_ALL];

	char m_key[256];
	char m_keyState[2][256];

	BYTE m_nowKey;           // 今押したキー
	BYTE m_prevKey;          // 前に押したキー

	int key;      // キー入力情報格納

	static const int LSTICK_DEADZONE;
};