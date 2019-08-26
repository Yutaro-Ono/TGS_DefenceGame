//-----------------------------------------------------------+
// TextGraphクラス
//      : テキストフォントの設定、描画クラス
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

	void DrawTextMessage(int x, int y, const char* string);          // メッセージ風表示（文字数制限あり）


private:

	int m_fontImg[256];              // フォント画像格納用
	int m_fontMap[256];

	int isString(const char c);

	static const int SIZE_X;         // 一文字のフォント横サイズ
	static const int SIZE_Y;         // 一文字のフォント縦サイズ
	static const int DIV_SIZE_X;     // 横方向の分割数
	static const int DIV_SIZE_Y;     // 縦方向の分割数
	static const int FONT_ALL_NUM;       // フォントの最大数
};