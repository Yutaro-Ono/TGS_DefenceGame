#pragma once
#include "InterfacePlayer.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"


class Player;

class InGameUIManager final
{
public:

	InGameUIManager();
	~InGameUIManager();

	void Initialize();

	void Update(Player& player);

	void Draw(Player& player);

private:

	int m_tutorialGraph;               // チュートリアルの画像ハンドル

	InterfacePlayer* m_playerUI;       // プレイヤーのUI

};