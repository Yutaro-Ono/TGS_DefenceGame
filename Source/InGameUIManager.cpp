//-----------------------------------------------------------------------+
// ゲーム中におけるインターフェース統括クラス
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "InGameUIManager.h"
#include "InterfacePlayer.h"

// コンストラクタ
InGameUIManager::InGameUIManager()
{
	// 処理なし
}

// デストラクタ
InGameUIManager::~InGameUIManager()
{
	// 処理なし
}

// 各種初期化処理
void InGameUIManager::Initialize()
{
	m_score = 0;

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

	// スコアを更新
	m_nowScore = m_score->GetScore();
}

// 描画処理
void InGameUIManager::Draw(Player& player, TextGraph& text)
{
	// プレイヤーステータスの描画
	m_playerUI->Draw(player, text);

	// スコアの描画
	m_score->Draw(text);
	m_score->DrawAddScore(text);
}
