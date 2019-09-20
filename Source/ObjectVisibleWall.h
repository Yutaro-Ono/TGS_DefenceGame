//-----------------------------------------------------------+
// 見えない壁クラス
//      : フィールド上の見えない壁(入場不可エリア用)
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "ObjectBase.h"
#include "HitChecker.h"

class ObjectVisibleWall
{

public:

	ObjectVisibleWall();                   // コンストラクタ
	~ObjectVisibleWall();                  // デストラクタ

	void Update(float deltaTime);          // 更新処理

	//-------------------------------------------------------------+
	// Getter/Setter関連
	//-------------------------------------------------------------+
	// ポジションのセッター
	void SetPosition(const VECTOR in_position) { m_position = in_position; }


private:

	VECTOR     m_position;          // ポジション

};