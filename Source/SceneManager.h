//---------------------------------------------------------------------+
// シーンマネージャークラス
//      : シーン処理を総合的に管理するクラスだが、現時点では未実装
//                                                   2019 Yutaro Ono.
//---------------------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"

class SceneManager final
{

public:

	SceneManager();             // コンストラクタ
	~SceneManager();            // デストラクタ

	void Initialize();          // 各種初期化処理

	void Delete();              // 各種解放処理

	void Update();              // 更新処理

};