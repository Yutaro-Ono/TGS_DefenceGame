#include "TextGraph.h"

const int TextGraph::SIZE_X = 64;
const int TextGraph::SIZE_Y = 64;
const int TextGraph::DIV_SIZE_X = 17;
const int TextGraph::DIV_SIZE_Y = 6;
const int TextGraph::FONT_ALL_NUM = 89;

// �R���X�g���N�^
TextGraph::TextGraph()
{
	for (int i = 0; i < FONT_ALL_NUM; i++)
	{
		m_fontMap[i] = -1;
	}
}

// �f�X�g���N�^
TextGraph::~TextGraph()
{
}

// �e�평����
void TextGraph::Initialize()
{
	// �t�H���g�摜�𕪊����[�h
	LoadDivGraph("Data/Interface/Fonts/Font_Liner.png", FONT_ALL_NUM, DIV_SIZE_X, DIV_SIZE_Y, SIZE_X, SIZE_Y, m_fontImg);
	// �e�L�X�g�̏���
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

// �e��������
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
	//�e�L�X�g�`��J�n
	int text_x, text_y, img;
	text_x = x;
	text_y = y;

	while (*string)
	{
		// ���������s�̏ꍇ�͉��s�{�߂�
		if (*string == '\n')
		{
			text_x = x;
			text_y += SIZE_Y;
			string++;
			continue;
		}

		//�����`��
		img = isString(*string);
		if (img >= 0)
		{
			DrawGraph(text_x, text_y, m_fontImg[img], TRUE);
		}

		// �����`��ʒu�i�߂�
		text_x += SIZE_X;
		string++;
	}
}

// �������t�H���g�C���[�W�̓Y�����Ƃ��ĕϊ�
int TextGraph::isString(const char c)
{
	return m_fontMap[c];
}
