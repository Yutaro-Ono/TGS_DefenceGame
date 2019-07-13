//-----------------------------------------------------------+
// カメラクラス
//      : カメラの設定，更新を管理
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"

class PlayerManager;

class Camera final
{
public:
	Camera();							// コンストラクタ
	~Camera();							// デストラクタ

	// 更新
	void Update(PlayerManager& playerManager);	

	//---------------------------------------------------+
	// Getter/Setter 関連
	//---------------------------------------------------+
	// ポジションのゲッター/セッター
	const VECTOR& GetPos() const { return m_position; }

private:

	VECTOR	m_position;			            // ポジション

};