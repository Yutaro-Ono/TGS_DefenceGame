//-----------------------------------------------------------+
// エネミークラス
//      : エネミーの固有処理
//                                  Last Update : 2019/07/03
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

	enum STATE
	{
		NONE = 0,
		ACTIVE,
		DEAD,
	};

	Enemy(int sourceModelHandle);                    // コンストラクタ
	~Enemy();                                        // デストラクタ

	void Initialize() override;                      // 各種初期化処理

	void Delete()override {};

	void Update(float deltaTime)override;

	void SetEmergence(const VECTOR popPos);             // 最初の出現位置設定

	void GazeTarget(PlayerManager& playerManager, float deltaTime);                               // ターゲットの方向に向く

private:

	VECTOR m_targetVec;



	static const VECTOR SCALE_SIZE;                        // 拡大率
	static const float MOVE_SPEED;
};