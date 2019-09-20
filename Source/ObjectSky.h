//-----------------------------------------------------------+
// スカイドームクラス
//      : スカイドーム(空)の描画を実行
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "ObjectBase.h"

class ObjectSky : public ObjectBase
{

public:

	ObjectSky(int sourceModelHandle);               // コンストラクタ
	~ObjectSky();                                   // デストラクタ

	void Initialize() override;                     // 各種初期化

	void Update(float deltaTime) override;          // 更新処理


private:

	static const VECTOR SCALE_SIZE;          // モデルの拡大率
	static const VECTOR ROTATE_RAD;          // モデルの回転方向

};