//-----------------------------------------------------------------------+
// ゲーム中におけるインターフェース統括クラス
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "InGameUIManager.h"
#include "InterfacePlayer.h"

// コンストラクタ
InGameUIManager::InGameUIManager()
{
	//m_tutorialGraph = LoadGraph("Data/Interface/Control_Tutorial.png");
}

// デストラクタ
InGameUIManager::~InGameUIManager()
{

}

// 各種初期化処理
void InGameUIManager::Initialize()
{
	// プレイヤーステータスUI
	m_playerUI = new InterfacePlayer();
	m_playerUI->Initialize();
	// スコア
	m_score = new Score();
	m_score->Initialize();
}

// 各種解放処理
void InGameUIManager::Delete()
{
	delete (m_playerUI);
	delete (m_score);
}

// 更新処理
void InGameUIManager::Update(Player & player)
{
	m_score->Update(player);
	m_playerUI->Update(player);
}

// 描画処理
void InGameUIManager::Draw(Player& player, TextGraph& text)
{
	// プレイヤーステータスの描画
	m_playerUI->Draw(player, text);

	// スコアの描画
	m_score->Draw(text);

	// チュートリアル画像(α版用)
	// DrawGraph(1280, 50, m_tutorialGraph, TRUE);
}
