//-----------------------------------------------------------+
// ゲーム中におけるインターフェース統括クラス
//      : ゲーム中に表示するインターフェースの総合的な処理を行う
//                                  Last Update : 2019/07/28
//-----------------------------------------------------------+
#pragma once
#include "InterfacePlayer.h"
#include "Score.h"
#include "Actor.h"
#include "Player.h"
#include "PlayerManager.h"
#include "GameSystem.h"
#include "TextGraph.h"

class Player;
class InterfacePlayer;
class TextGraph;
class Score;

class InGameUIManager final
{
public:

	InGameUIManager();
	~InGameUIManager();

	void Initialize();                  // 各種初期化

	void Delete();                      // 各種削除処理

	void Update(Player& player);        // 更新処理

	void Draw(Player& player, TextGraph& text);          // 描画処理

private:

	int m_tutorialGraph;               // チュートリアルの画像ハンドル

	InterfacePlayer* m_playerUI;       // プレイヤーのUI
	Score* m_score;                    // スコア
};