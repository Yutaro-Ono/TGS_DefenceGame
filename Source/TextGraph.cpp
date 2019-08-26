#include "TextGraph.h"

const int TextGraph::SIZE_X = 64;
const int TextGraph::SIZE_Y = 64;
const int TextGraph::DIV_SIZE_X = 17;
const int TextGraph::DIV_SIZE_Y = 6;
const int TextGraph::FONT_ALL_NUM = 89;

// コンストラクタ
TextGraph::TextGraph()
{
	for (int i = 0; i < FONT_ALL_NUM; i++)
	{
		m_fontMap[i] = -1;
	}
}

// デストラクタ
TextGraph::~TextGraph()
{
}

// 各種初期化
void TextGraph::Initialize()
{
	// フォント画像を分割ロード
	LoadDivGraph("Data/Interface/Fonts/Font_Liner.png", FONT_ALL_NUM, DIV_SIZE_X, DIV_SIZE_Y, SIZE_X, SIZE_Y, m_fontImg);
	// テキストの順序
	TextMapping("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!?#$%&()-=.,/_\\<>@`[]{}*+;:");
}

void TextGraph::TextMapping(const char * in_text)
{
	int num = 0;
	const char *p;

	p = in_text;
	char n = 0;

	while (*p && n < 255)
	{
		m_fontMap[*p++] = n++;
	}

}

// 各種解放処理
void TextGraph::Delete()
{
	for (int i = 0; i < FONT_ALL_NUM; i++)
	{
		DeleteGraph(m_fontImg[i]);
	}
}

void TextGraph::Update()
{
}

void TextGraph::Draw()
{
}

void TextGraph::DrawTextMessage(int x, int y, const char * string)
{
	//テキスト描画開始
	int text_x, text_y, img;
	text_x = x;
	text_y = y;

	while (*string)
	{
		// 文字が改行の場合は改行＋戻す
		if (*string == '\n')
		{
			text_x = x;
			text_y += SIZE_Y;
			string++;
			continue;
		}

		//文字描画
		img = isString(*string);
		if (img >= 0)
		{
			DrawGraph(text_x, text_y, m_fontImg[img], TRUE);
		}

		// 文字描画位置進める
		text_x += SIZE_X;
		string++;
	}
}

// 文字をフォントイメージの添え字として変換
int TextGraph::isString(const char c)
{
	return m_fontMap[c];
}
