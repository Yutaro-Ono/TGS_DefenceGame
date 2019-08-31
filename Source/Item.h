//-----------------------------------------------------------+
// アイテムクラス
//      : アイテム
//                                  Last Update : 2019/07/25
//-----------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class Item : public ObjectBase
{
public:

	enum STATE_ITEM
	{
		NONE,
		POP,
		ACTIVE,
		DEACTIVE,
		DEAD
	};

	Item(int sourceModelHandle);
	~Item();

	void Initialize();                // 各種初期化処理

	void Update(float deltaTime);                    // 更新処理

	void Fall(float deltaTime);       // 出現時の落下処理

	void Draw();



	// 状態のゲッター
	const int& GetState() const { return m_state; }

	// ポジションのセッター
	void SetEmergence(const VECTOR popPos) { m_position = popPos; }
	// Deactive(無効)状態へのセッター
	void SetDeactive() { m_state = Item::DEACTIVE; }

private:

	float m_hitRadius;         // 当たり判定用の半径

	int m_state;               // ゲーム中の状態

	static const float FALL_SPEED;       // 落下速度
};