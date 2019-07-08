//-----------------------------------------------------------+
// プレイヤークラス
//      : プレイヤーの固有処理 (アクタークラスを継承)
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Input.h"
#include "Enemy.h"

class Enemy;

class Player : public Actor
{
public:
	Player(const int sourceModelHandle);                         // コンストラクタ
	~Player();                                                   // デストラクタ

	void Initialize() override {};

	void Delete() override {};

	void Update(float deltaTime)override {};
	void Update(Input& input, float deltaTime);                       // プレイヤー関連の更新

	void Draw()override;                                         // プレイヤーの描画

	void MotionMove(float deltaTime);                            // 移動のモーション

	// 当たり判定関連の処理
	const float& GetRadius()const { return m_hitRadius; }        // 当たり判定半径のゲッター
	void SetHitEnemy(bool hit_e) { m_hitEnemy = hit_e; }         // エネミーとの当たり判定フラグのセッター
	void OnHitEnemy(Enemy& enemy);                               // エネミーとの当たり判定処理

	// void SetHitInterval();

private:

	VECTOR m_velocity;                        // 加速度

	float velocityY;                          // 上方向加速度

	float m_hitRadius;                        // 当たり判定用半径
	bool m_hitEnemy;                            // エネミーに当たったかどうかのフラグ

	static const float MOVE_SPEED;            // プレイヤーの移動速度

	static const float INITIAL_POSITION_Y;    // PlayerのプレイヤーのY座標

	static const VECTOR SCALE_SIZE;           // 拡大率のサイズ

	bool m_moveFlag;                          // 移動しているかどうかのフラグ
	static const float JUMP_POWER;            // 移動モーションにおける小刻みジャンプの上方向パワー
	static const float JUMP_SUB;              // 移動モーションにおける小刻みジャンプの減算処理に用いる
	
};

