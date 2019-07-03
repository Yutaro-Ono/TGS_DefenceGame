//---------------------------------------------------------------+
// フィールドオブジェクトクラス
//      : フィールドの固有処理 (オブジェクト基底クラスを継承)
//                                      Last Update : 2019/07/01
//---------------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class ObjectField : public ObjectBase
{
public:

	ObjectField(int sourceModelHandle);
	~ObjectField();

	void Initialize() override;

	void Update() override;



private:



};