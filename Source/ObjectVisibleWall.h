//-----------------------------------------------------------+
// 見えない壁クラス
//      : フィールド上の見えない壁(入場不可エリア用)
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ObjectBase.h"

class ObjectVisibleWall : public ObjectBase
{
public:

	ObjectVisibleWall(int m_modelHandle);
	~ObjectVisibleWall();

private:

};