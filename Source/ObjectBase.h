//-----------------------------------------------------------+
// オブジェクト基底クラス
//      : オブジェクト関連(主にフィールド構成物)
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ModelLoader.h"

class ObjectBase
{
public:
	ObjectBase(int sourceModelHandle);
	virtual ~ObjectBase();

	virtual void Initialize() = 0;

	virtual void Update(float deltaTime) = 0;

	virtual void Draw();

	// ポジションのゲッター/セッター
	const VECTOR& GetPosition() const { return m_position; };
	void SetPos(const VECTOR set) { m_position = set; }
	// 半径の取得(当たり判定用)
	const float& GetRadius() const{ return m_radius; }

protected:

	VECTOR m_position;
	VECTOR m_direction;
	float m_radius;

	int m_modelHandle;

};