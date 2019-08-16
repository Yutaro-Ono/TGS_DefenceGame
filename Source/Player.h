//-----------------------------------------------------------+
// プレイヤークラス
//      : プレイヤーの固有処理 (アクタークラスを継承)
//                                  Last Update : 2019/07/28
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

	void Initialize() override;                                  // 初期化処理

	void Delete() override {};                                   // 各種解放処理

	void Update(float deltaTime) override;                       // プレイヤー関連の更新(オーバーライド)

	void Update(Input& input, float deltaTime);                  // プレイヤー関連の更新

	void Draw()override;                                         // プレイヤーの描画

	void HitWallUpdate(float deltaTime);                         // 簡易的なフィールドの当たり判定

	void MotionMove(float deltaTime);                            // 移動のモーション

	void OnHitEnemy(Enemy& enemy);                               // エネミーとの当たり判定処理
	void HitInterval();                                          // エネミー衝突時、次の当たり判定処理が行われるまでのインターバル

	//----------------------------------------------------------------------------------------------------------------+
	// Getter/Setter 関連
	//----------------------------------------------------------------------------------------------------------------+
	const float& GetRadius()const { return m_hitRadius; }                                 // 当たり判定半径のゲッター
	const bool& GetHitEnemy() const { return m_hitEnemy; }                                // エネミーと当たったかどうかのゲッター
	const int& GetHitPoint() const { return m_hitPoint; }                                 // プレイヤー体力のゲッター
	// アイテム関連
	const int& GetHoldItem() const { return m_holdItemNum; }                              // 所持しているアイテムの数を返す
	const int& GetMaxHold() const { return Player::MAX_HOLDITEM; }                        // 所持できるアイテムの最大数を返す
	void AddHoldItem() { m_holdItemNum++; };                                              // 所持しているアイテムの数を増やす
	void InitHoldItem() { m_holdItemNum = 0; }                                            // アイテム回収時、ホールドアイテムのリセット用
	// スコア関連
	const bool& GetDeliveredItem() const { return m_deliverdItem; }                       // アイテムを回収したかどうかのゲッター
	void SetDeliveredItem(bool in_delivered) { m_deliverdItem = in_delivered; }           // アイテムを回収したかどうかのセッター

	void SetHitEnemy(bool hit_e) { m_hitEnemy = hit_e; }                                  // エネミーとの当たり判定フラグのセッター
	void SetInterval(const int count) { m_hitTime = count; }                              // インターバルのセッター
	void SetDamaged() { m_hitPoint -= 1; }                                                // エネミー衝突時、体力減算処理



private:

	int m_hitPoint;                                              // プレイヤー体力

	VECTOR m_velocity;                                           // 加速度

	float velocityY;                                             // 上方向加速度

	bool m_moveFlag;                                             // 移動しているかどうかのフラグ

	int m_holdItemNum;                                           // 現在所持しているスコアアイテムの数(スコアアイテムに衝突で加算、回収地点にもっていくと初期化しスコア加算)
	bool m_deliverdItem;                                         // スコアを回収ポッドにもっていったかどうか

	float m_hitRadius;                                           // 当たり判定用半径
	bool m_hitEnemy;                                             // エネミーに当たったかどうかのフラグ
	int m_hitTime;                                               // 当たり判定が連続で発生するまでのインターバル

	static const float MOVE_SPEED;                               // プレイヤーの移動速度
	static const float INITIAL_POSITION_Y;                       // PlayerのプレイヤーのY座標
	static const VECTOR SCALE_SIZE;                              // 拡大率のサイズ
	static const int MAX_HP;                                     // 体力の最大値
	static const float JUMP_POWER;                               // 移動モーションにおける小刻みジャンプの上方向パワー
	static const float JUMP_SUB;                                 // 移動モーションにおける小刻みジャンプの減算処理に用いる
	static const int MAX_HOLDITEM;                               // アイテムの最大所持数
};

