//-----------------------------------------------------------+
// ディレクション(演出)ベースクラス
//      : ゲーム内の演出の基底クラス
//                                  Last Update : 2019/08/04
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"


class DirectionBase
{
public:

	DirectionBase();                       // コンストラクタ
	~DirectionBase();                      // デストラクタ

	virtual void Initialize() = 0;         // 各種初期化(純粋仮想関数)

	// 演出の状態を取得する
	const bool& GetActive() const { return m_activate; }


private:

	bool m_activate;                       // この演出がアクティブかどうか


};