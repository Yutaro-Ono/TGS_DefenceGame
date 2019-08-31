#pragma once
#include "InterfaceBase.h"
#include "InGameUIManager.h"
#include "Score.h"
#include "Player.h"
#include "TextGraph.h"

class TextGraph;

class InterfacePlayer : public InterfaceBase
{
public:

	InterfacePlayer();
	~InterfacePlayer();

	void Initialize() override;

	void Update() override;

	void Update(Player& player, Score& score);

	void Draw(Player& player, TextGraph& text);

private:

	// ���W
	VECTOR m_stockPosition;                   // �A�C�e���X�g�b�N��UI�̍��W
	VECTOR m_scorePosition;                   // �X�R�A�̍��W
	VECTOR m_getPosition;                     // �擾�����X�R�A�̍��W

	// �X�R�A�A�C�e��������
	int m_holdItem;

	// �擾�X�R�A�֘A
	bool m_get;                         // �X�R�A���擾�����t���O
	int m_getScore;                     // �擾�����X�R�A�̒l

	// �摜�n���h���֘A
	int hpGauge[5];
	int hpFrame;

};