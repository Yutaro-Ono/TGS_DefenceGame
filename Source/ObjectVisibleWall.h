//-----------------------------------------------------------+
// 見えない壁クラス
//      : フィールド上の見えない壁(入場不可エリア用)
//                                  Last Update : 2019/07/06
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ObjectBase.h"
#include "HitChecker.h"



class ObjectVisibleWall
{
public:

	ObjectVisibleWall();
	~ObjectVisibleWall();

	void SetPosition(const VECTOR in_position) { m_position = in_position; }

	void Update();

private:

	VECTOR m_position;
};