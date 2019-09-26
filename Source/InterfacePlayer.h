//-----------------------------------------------------------------------+
// インターフェース(プレイヤーステータス)クラス                                     
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+
#pragma once

// インクルードファイル
#include "InterfaceBase.h"
#include "InGameUIManager.h"
#include "Score.h"
#include "Player.h"
#include "TextGraph.h"
#include "Timer.h"

// クラス前方宣言
class TextGraph;
class Timer;

class InterfacePlayer : public InterfaceBase
{

public:

	InterfacePlayer();                                   // コンストラクタ
	~InterfacePlayer();                                  // デストラクタ

	void Initialize() override;                          // 初期化処理

	void Delete();                                       // 解放処理

	void Update() override;                              // 更新処理

	void Update(Player& player);                         // 更新処理(プレイヤー追跡)

	void Draw(Player& player, TextGraph& text);          // 描画処理


private:

	VECTOR m_stockPosition;          // アイテムストック数UIの座標
	VECTOR m_scorePosition;          // スコアの座標

	int m_holdItem;                  // スコアアイテム所持数

	int hpGauge[5];                  // HPゲージ
	int hpFrame;                     // HPゲージフレーム

};