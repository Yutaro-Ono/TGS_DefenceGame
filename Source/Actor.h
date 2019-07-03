//----------------------------------------------------------------------+
// アクター基底クラス
//      : アクター(移動するオブジェクト，キャラクター)
//                                             Last Update : 2019/07/01
//----------------------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ObjectBase.h"
class Actor
{
public:
	Actor(const int sourceModelHandle);
	virtual ~Actor();

	virtual void Initialize() = 0;

	virtual void Update() = 0;
	void Draw();

	// ポジションのゲッター/セッター
	const VECTOR& GetPosition() const { return m_position; };
	void SetPos(const VECTOR set) { m_position = set; }
	// 半径の取得(当たり判定用)
	float GetRadius() const { return m_radius; }

protected:

	VECTOR m_position;
	VECTOR m_direction;
	float m_radius;

	int m_modelHandle;

};