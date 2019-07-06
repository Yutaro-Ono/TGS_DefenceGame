//-----------------------------------------------------------+
// プレイヤークラス
//      : プレイヤーの固有処理 (アクタークラスを継承)
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Input.h"

class Player : public Actor
{
public:
	Player(const int sourceModelHandle);   // コンストラクタ
	~Player();                             // デストラクタ

	void Initialize() override {};

	void Delete() override {};

	void Update(float deltaTime) override;     // プレイヤー関連の更新

	void MotionMove(float deltaTime);          // 移動のモーション

private:

	VECTOR m_velocity;                     // 加速度

	float velocityY;

	bool m_jumpFlag;                      // ジャンプフラグ

	static const float MOVE_SPEED;          // プレイヤーの移動速度

	static const float INITIAL_POSITION_Y;    // PlayerのプレイヤーのY座標

	static const VECTOR SCALE_SIZE;        // 拡大率のサイズ

	static const float JUMP_POWER;         // 移動モーションにおける小刻みジャンプの上方向パワー
	static const float JUMP_SUB;           // 移動モーションにおける小刻みジャンプの減算処理に用いる
	
};

