#include "InGameUIManager.h"
#include "InterfacePlayer.h"


InGameUIManager::InGameUIManager()
{
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
}
