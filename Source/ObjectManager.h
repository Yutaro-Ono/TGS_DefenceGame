//-----------------------------------------------------------+
// オブジェクトマネージャークラス
//      : オブジェクトの総合的な処理を行う
//                                         2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include <vector>
#include "Common.h"
#include "ObjectBase.h"
#include "ObjectField.h"
#include "ObjectPod.h"

class ObjectManager final
{

public:

	ObjectManager();                       // コンストラクタ
	~ObjectManager();                      // デストラクタ

	void Initialize();                     // 初期化処理
	void Delete();                         // 解放処理

	void Update(float deltaTime);          // 更新処理

	void Draw();                           // 描画処理

	//-------------------------------------------------------------+
    // Getter/Setter関連
    //-------------------------------------------------------------+

	ObjectBase* GetPodPointer() { return m_podObj; }          // 回収ポッドのポインタゲッター


private:

	int       m_skySourceHandle;          // スカイドームのハンドル
	int       m_podSourceHandle;          // 回収ポッドのハンドル
	int     m_fieldSourceHandle;          // フィールドモデルのハンドル

	ObjectBase*        m_skyObj;          // 空
	ObjectBase*        m_podObj;          // 回収ポッド
	ObjectBase*      m_fieldObj;          // フィールド

};