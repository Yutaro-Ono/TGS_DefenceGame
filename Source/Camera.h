//-----------------------------------------------------------+
// カメラクラス
//      : カメラの設定，更新を管理
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"

// クラス前方宣言
class PlayerManager;

class Camera final
{

public:

	Camera();                                           // コンストラクタ
	~Camera();                                          // デストラクタ

	void Update(PlayerManager& playerManager);          // 更新処理

	//---------------------------------------------------+
	// Getter/Setter 関連
	//---------------------------------------------------+
	// ポジションのゲッター/セッター
	const VECTOR& GetPos() const { return m_position; }


private:

	VECTOR     m_position;          // ポジション

};