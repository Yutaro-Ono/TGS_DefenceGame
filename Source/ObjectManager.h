//-----------------------------------------------------------+
// オブジェクトマネージャークラス
//      : オブジェクトの総合的な処理を行う
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ObjectBase.h"
#include "ObjectField.h"

#define OBJECT_NUM_W 5
#define OBJECT_NUM_H 5

class ObjectManager final
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void Delete();

	void Update();

	void Draw();

private:

	int m_fieldSourceHandle;           // フィールドモデルのハンドル
	int m_skySourceHandle;             // スカイドームのハンドル

	ObjectBase* m_fieldObj;            // フィールド
	ObjectBase* m_skyObj;              // 空

	ObjectBase* m_object[OBJECT_NUM_H][OBJECT_NUM_W];
};