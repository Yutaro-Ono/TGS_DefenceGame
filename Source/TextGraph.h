//-----------------------------------------------------------+
// TextGraph�N���X
//      : �e�L�X�g�t�H���g�̐ݒ�A�`��N���X
//                                  Last Update : 2019/08/24
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"


class TextGraph
{
public:

	TextGraph();
	~TextGraph();

	void Initialize();

	void TextMapping(const char* in_text);

	void Delete();

	void Update();

	void Draw();

	void DrawTextMessage(int x, int y, const char* string);          // ���b�Z�[�W���\���i��������������j


private:

	int m_fontImg[256];              // �t�H���g�摜�i�[�p
	int m_fontMap[256];

	int isString(const char c);

	static const int SIZE_X;         // �ꕶ���̃t�H���g���T�C�Y
	static const int SIZE_Y;         // �ꕶ���̃t�H���g�c�T�C�Y
	static const int DIV_SIZE_X;     // �������̕�����
	static const int DIV_SIZE_Y;     // �c�����̕�����
	static const int FONT_ALL_NUM;       // �t�H���g�̍ő吔
};