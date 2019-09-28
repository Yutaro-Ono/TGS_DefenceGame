//---------------------------------------------------------------+
// フィールドオブジェクトクラス
//      : フィールドの固有処理 (オブジェクト基底クラスを継承)
//                                              2019 Yutaro Ono.
//---------------------------------------------------------------+
#pragma once

// インクルードファイル
#include "ObjectBase.h"

class ObjectField : public ObjectBase
{

public:

	ObjectField(int sourceModelHandle);             // コンストラクタ
	~ObjectField();                                 // デストラクタ

	void Initialize() override;                     // 初期化処理

	void Update(float deltaTime) override;          // 更新処理


private:

	VERTEX3D     m_vertex[6];          // 頂点情報格納

	static const VECTOR SCALE_SIZE;          // モデルの拡大率

};