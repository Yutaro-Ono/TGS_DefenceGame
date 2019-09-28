//-----------------------------------------------------------------------+
// オブジェクト基底クラス                                   
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "ObjectBase.h"

// コンストラクタ
ObjectBase::ObjectBase(int sourceModelHandle)
{
	// 引数のモデルを自身のハンドルに複製
	m_modelHandle = MV1DuplicateModel(sourceModelHandle);
}

// デストラクタ
ObjectBase::~ObjectBase()
{
	// モデルの削除
	MV1DeleteModel(m_modelHandle);
}

// 描画処理
void ObjectBase::Draw()
{
	// モデルを描画
	MV1DrawModel(m_modelHandle);
	// 当たり判定確認用の球体
	// DrawSphere3D(m_position, m_radius, 5, 0x00ffff, 0x00ffff, FALSE);
}