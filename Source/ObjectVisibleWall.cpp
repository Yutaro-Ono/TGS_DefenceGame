//-----------------------------------------------------------+
// 見えない壁クラス
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+

// インクルードファイル
#include "ObjectVisibleWall.h"

// コンストラクタ
ObjectVisibleWall::ObjectVisibleWall()
{
	// 処理なし
}

// デストラクタ
ObjectVisibleWall::~ObjectVisibleWall()
{
	// 処理なし
}

// 更新処理
void ObjectVisibleWall::Update(float deltaTime)
{
	// 当たり判定確認用の球
	DrawSphere3D(m_position, 3.0f, 5, 0x00ffff, 0x00ffff, FALSE);
}
