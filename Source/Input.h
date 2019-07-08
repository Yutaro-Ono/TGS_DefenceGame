//-----------------------------------------------------------+
// キー入力関連クラス
//      : キーボードの押下状態を取得する
//                                  Last Update : 2019/07/08
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"


class Input final
{
public:

	Input();
	~Input();

	void KeyChecker();

	const int& GetKeyPad() const { return key; };

private:

	int key;      // キー入力情報格納

};