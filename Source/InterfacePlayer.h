#pragma once
#include "InterfaceBase.h"
#include "InGameUIManager.h"
#include "Score.h"
#include "Player.h"
#include "TextGraph.h"
#include "Timer.h"

class TextGraph;
class Timer;

class InterfacePlayer : public InterfaceBase
{
public:

	InterfacePlayer();
	~InterfacePlayer();

	void Initialize() override;

	void Delete();

	void Update() override;

	void Update(Player& player);

	void Draw(Player& player, TextGraph& text);

private:

	// ���W
	VECTOR m_stockPosition;                   // �A�C�e���X�g�b�N��UI�̍��W
	VECTOR m_scorePosition;                   // �X�R�A�̍��W


	// �X�R�A�A�C�e��������
	int m_holdItem;


	// �摜�n���h���֘A
	int hpGauge[5];
	int hpFrame;

};