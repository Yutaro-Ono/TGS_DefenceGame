//----------------------------------------------------------------------+
// アクター基底クラス
//      : アクター(移動するオブジェクト，キャラクター)
//                                                     2019 Yutaro Ono.
//----------------------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "ObjectBase.h"

class Actor
{

public:

	Actor(const int sourceModelHandle);                // コンストラクタ
	virtual ~Actor();                                  // デストラクタ

	virtual void Initialize() = 0;                     // 初期化処理
	virtual void Delete() = 0;                         // 解放処理

	virtual void Update(float deltaTime) = 0;          // 更新処理
	virtual void Draw() = 0;                           // 描画処理

	//--------------------------------------------------------------------------+
    // Getter/Setter 関連
    //--------------------------------------------------------------------------+
	// ポジションのゲッター
	virtual const VECTOR& GetPosition() const { return m_position; }
	// ポジションのセッター
	virtual void SetPos(const VECTOR set) { m_position = set; }
	// 半径の取得(当たり判定用)
	virtual const float& GetRadius() const = 0;


protected:

	VECTOR      m_position;          // ポジション
	VECTOR     m_direction;          // 方向

	float          m_angle;          // 角度
	float      m_hitRadius;          // 当たり判定用の半径

	int      m_modelHandle;          // モデルのハンドル

};