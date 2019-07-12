#include "InGameUIManager.h"
#include "InterfacePlayer.h"


InGameUIManager::InGameUIManager()
{
	m_tutorialGraph = LoadGraph("Data/Interface/Control_Tutorial.png");
}

InGameUIManager::~InGameUIManager()
{
	delete (m_playerUI);
}

void InGameUIManager::Initialize()
{
	m_playerUI = new InterfacePlayer();
	m_playerUI->Initialize();
}

void InGameUIManager::Update(Player & player)
{
	
}

void InGameUIManager::Draw(Player & player)
{
	m_playerUI->Draw(player);

	// チュートリアル画像(α版用)
	DrawGraph(1280, 50, m_tutorialGraph, TRUE);
}
