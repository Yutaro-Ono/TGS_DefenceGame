//-----------------------------------------------------------+
// エネミークラス
//      : エネミーの固有処理
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Math.h"
#include "Actor.h"
#include "PlayerManager.h"

class PlayerManager;

class Enemy : public Actor
{
public:

	// 状態定義
	enum STATE
	{
		NONE = 0,
		ACTIVE,
		DEAD,
	};

	Enemy(int sourceModelHandle);                                       // コンストラクタ
	~Enemy();                                                           // デストラクタ

	void Initialize() override;                                         // 各種初期化処理
	void Delete()override {};
	void Update(float deltaTime)override;                               // 更新処理
	void Draw()override;                                                // 描画処理

	void SetEmergence(const VECTOR popPos);                             // 最初の出現位置設定

	void OnHitOtherEnemy(Enemy& other_enemy);                           // 他エネミーと当たった時の処理

	void ChaseTarget(PlayerManager& playerManager, float deltaTime);    // ターゲット(プレイヤー)の追跡処理
	void HitInterval();                                                 // プレイヤーと衝突時、次の当たり判定が行われるまでのインターバル計測関数

	//-------------------------------------------------------------+
	// Getter/Setter関連
	//-------------------------------------------------------------+
	const bool& GetHitPlayer()const { return m_hitPlayer; }             // プレイヤーと衝突しているかどうかのゲッター
	const float& GetRadius()const { return m_hitRadius; }               // エネミーの半径取得

	void SetHitPlayer(bool p_hit) { m_hitPlayer = p_hit; }              // プレイヤーと衝突しているかどうかのセッター
	void SetInterval(const int count) { m_hitTime = count; }            // インターバルのセッター



private:

	VECTOR m_targetVec;                                                 // ターゲット(プレイヤー)のベクトル

	float m_hitRadius;                                                  // 当たり判定用半径

	bool m_hitPlayer;                                                   // プレイヤーに当たっているかどうかのフラグ
	int m_hitTime;                                                      // プレイヤーに当たっている時に用いるインターバル


	static const VECTOR SCALE_SIZE;                                     // モデルの拡大率
	static const float MOVE_SPEED;                                      // 移動速度
};