//-----------------------------------------------------------+
// 回収ポッドクラス
//      : アイテム回収用のポッド
//                                  Last Update : 2019/07/29
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "ObjectBase.h"
#include "Effect.h"

// クラス前方宣言
class PlayEffect;

class ObjectPod : public ObjectBase
{

public:

	ObjectPod(int sourceModelHandle);               // コンストラクタ
	~ObjectPod();                                   // デストラクタ

	void Initialize();                              // 初期化処理
	void Delete();                                  // 解放処理

	void Update(float deltaTime) override;          // 更新処理


private:

	PlayEffect*     m_effect;          // ポッドのエフェクト


	static const VECTOR           SCALE_SIZE;              // モデルの拡大率サイズ
	static const VECTOR     INITIAL_POSITION;              // ポッドの初期座標(固定値)
	static const float            HIT_RADIUS;              // 当たり判定用の半径の定数

};