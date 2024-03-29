//-----------------------------------------------------------+
// アイテムクラス
//      : アイテム
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "ObjectBase.h"

class Item : public ObjectBase
{

public:

	// 状態enum
	enum STATE_ITEM
	{
		NONE,
		POP,
		ACTIVE,
		DEACTIVE,
		DEAD
	};

	Item(int sourceModelHandle);           // コンストラクタ
	~Item();                               // デストラクタ

	void Initialize();                     // 各種初期化処理

	void Update(float deltaTime);          // 更新処理

	void Fall(float deltaTime);            // 出現時の落下処理

	void Draw();                           // 描画処理

	//-------------------------------------------------------------+
    // Getter/Setter関連
    //-------------------------------------------------------------+
	const int& GetState() const { return m_state; }                          // 状態のゲッター

	void SetEmergence(const VECTOR popPos) { m_position = popPos; }          // ポジションのセッター
	void SetDeactive() { m_state = Item::DEACTIVE; }                         // アイテムを無効状態にするセッター


private:

	float             m_hitRadius;          // 当たり判定用の半径
	int                   m_state;          // ゲーム中の状態

	static const float FALL_SPEED;          // 落下速度

};