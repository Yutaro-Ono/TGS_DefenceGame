//-----------------------------------------------------------+
// オブジェクトマネージャークラス
//      : オブジェクトの総合的な処理を行う
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include <vector>
#include "Common.h"
#include "ObjectBase.h"
#include "ObjectField.h"
#include "ObjectPod.h"

class ObjectManager final
{
public:
	ObjectManager();
	~ObjectManager();

	void Initialize();
	void Delete();

	void Update();

	void Draw();

	ObjectBase* GetPodPointer() { return m_podObj; }       // 回収ポッドのポインタゲッター

private:

	int m_fieldSourceHandle;                  // フィールドモデルのハンドル
	int m_skySourceHandle;                    // スカイドームのハンドル
	int m_podSourceHandle;                    // 回収ポッドのハンドル

	ObjectBase* m_fieldObj;                   // フィールド
	ObjectBase* m_skyObj;                     // 空
	ObjectBase* m_podObj;                     // 回収ポッド

};