//-----------------------------------------------------------+
// �L�[���͊֘A�N���X
//      : �L�[�{�[�h�̉�����Ԃ��擾����
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

	int key;      // �L�[���͏��i�[

};