//---------------------------------------------------------------+
// フィールドオブジェクトクラス
//      : フィールドの固有処理 (オブジェクト基底クラスを継承)
//                                      Last Update : 2019/07/02
//---------------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class ObjectField : public ObjectBase
{
public:

	ObjectField(int sourceModelHandle);
	~ObjectField();

	void Initialize() override;

	void Update(float deltaTime) override;



private:

	VERTEX3D m_vertex[6];

	static const VECTOR SCALE_SIZE;     // モデルの拡大率

};