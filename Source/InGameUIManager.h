//-----------------------------------------------------------+
// ゲーム中におけるインターフェース統括クラス
//      : ゲーム中に表示するインターフェースの総合的な処理を行う
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "InterfacePlayer.h"
#include "Score.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"
#include "GameSystem.h"
#include "TextGraph.h"

// クラス前方宣言
class Player;
class InterfacePlayer;
class TextGraph;
class Score;

class InGameUIManager final
{

public:

	InGameUIManager();                                         // コンストラクタ
	~InGameUIManager();                                        // デストラクタ

	void Initialize();                                         // 各種初期化
	void Delete();                                             // 各種削除処理

	void Update(Player& player);                               // 更新処理
	void Draw(Player& player, TextGraph& text);                // 描画処理

	const int& GetScore()const { return m_nowScore; }          // スコアのゲッター


private:

	int m_tutorialGraph;                  // チュートリアルの画像ハンドル

	int m_nowScore;                       // 現在のスコア

	InterfacePlayer* m_playerUI;          // プレイヤーのUI
	Score* m_score;                       // スコア

};