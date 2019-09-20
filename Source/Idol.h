//-----------------------------------------------------------+
// アイドル(護衛対象)クラス
//      : アイドルの固有処理
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "Actor.h"
#include "HitChecker.h"

class Idol : public Actor
{

public:

	Idol(int sourceModelHandle);                    // コンストラクタ
	~Idol() {};                                     // デストラクタ

	void Initialize() override;                     // 初期化処理
	void Delete() override;                         // 解放処理

	void Update(float deltaTime) override;          // 更新処理
	void Draw()override;                            // 描画処理

	//--------------------------------------------------------------------------+
    // Getter/Setter 関連
    //--------------------------------------------------------------------------+
	// 半径の取得
	const float& GetRadius()const { return m_hitRadius; }


private:

	static const VECTOR SCALE_SIZE;          // モデルの拡大率

};