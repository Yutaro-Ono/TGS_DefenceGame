//-----------------------------------------------------------+
// オブジェクト基底クラス
//      : オブジェクト関連(主にフィールド構成物)
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"

class ObjectBase
{

public:

	ObjectBase(int sourceModelHandle);                 // コンストラクタ
	virtual ~ObjectBase();                             // デストラクタ

	virtual void Initialize() = 0;                     // 初期化処理

	virtual void Update(float deltaTime) = 0;          // 更新処理

	virtual void Draw();                               // 描画処理

	//-------------------------------------------------------------+
	// Getter/Setter関連
	//-------------------------------------------------------------+
	// ポジションのゲッター
	const VECTOR& GetPosition() const { return m_position; };
	// ポジションのセッター
	void SetPos(const VECTOR set) { m_position = set; }
	// 半径の取得(当たり判定用)
	const float& GetRadius() const{ return m_radius; }

protected:

	VECTOR      m_position;          // ポジション
	VECTOR     m_direction;          // 方向
	float         m_radius;          // 半径

	int      m_modelHandle;          // モデルのハンドル

};