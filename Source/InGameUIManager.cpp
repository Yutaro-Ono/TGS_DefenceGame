//-----------------------------------------------------------------------+
// ゲーム中におけるインターフェース統括クラス
//                                              Last Update : 2019/07/28
//-----------------------------------------------------------------------+
#include "InGameUIManager.h"
#include "InterfacePlayer.h"

// コンストラクタ
InGameUIManager::InGameUIManager()
{
	m_tutorialGraph = LoadGraph("Data/Interface/Control_Tutorial.png");
}

// デストラクタ
InGameUIManager::~InGameUIManager()
{
	delete (m_playerUI);
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

// 更新処理
void InGameUIManager::Update(Player & player)
{
	
}

// 描画処理
void InGameUIManager::Draw(Player & player)
{
	// プレイヤーステータスの描画
	m_playerUI->Draw(player);

	// スコアの描画
	m_score->Draw();

	// チュートリアル画像(α版用)
	DrawGraph(1280, 50, m_tutorialGraph, TRUE);
}
