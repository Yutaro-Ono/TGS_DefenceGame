//-----------------------------------------------------------+
// ディレクション(演出)ベースクラス
//      : ゲーム内の演出の基底クラス
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"

class DirectorBase
{

public:

	DirectorBase();                         // コンストラクタ
	~DirectorBase();                        // デストラクタ

	virtual void Initialize() = 0;          // 各種初期化(純粋仮想関数)
	virtual void Delete() = 0;              // 各種解放処理(純粋仮想関数)

	//--------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------+
	// 演出の状態を取得する
	const bool& GetActive() const { return m_activate; }


protected:

	bool m_activate;                       // この演出がアクティブかどうか

};