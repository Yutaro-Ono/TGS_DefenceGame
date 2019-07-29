//-----------------------------------------------------------+
// 回収ポッドクラス
//      : アイテム回収用のポッド
//                                  Last Update : 2019/07/29
//-----------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class ObjectPod : public ObjectBase
{
public:

	ObjectPod(int sourceModelHandle);
	~ObjectPod();

	void Initialize();

	void Delete();

	void Update();



private:





	static const VECTOR INITIAL_POSITION;              // ポッドの初期座標(固定値)
	static const float HIT_RADIUS;                     // 当たり判定用の半径の定数
};