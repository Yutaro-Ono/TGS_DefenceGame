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

	// 座標
	VECTOR m_stockPosition;                   // アイテムストック数UIの座標
	VECTOR m_scorePosition;                   // スコアの座標


	// スコアアイテム所持数
	int m_holdItem;


	// 画像ハンドル関連
	int hpGauge[5];
	int hpFrame;

};