//-----------------------------------------------------------+
// シーン基底クラス
//      : 各シーンの基底クラス。共通処理を行う
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "TextGraph.h"

// クラス前方宣言
class Camera;
class Input;
class TextGraph;

class SceneBase
{

public:

	SceneBase();                                                                     // コンストラクタ
	virtual ~SceneBase();                                                            // デストラクタ

	virtual void Initialize() = 0;                                                   // 初期化処理

	virtual void Delete() = 0;                                                       // 解放処理

	virtual void Update(Camera& camera, Input& input, float deltaTime) = 0;          // 更新処理

	virtual void Draw(TextGraph& text) = 0;                                          // 描画処理

	//--------------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------------+
	// シーンが更新されたかどうかの取得
	virtual SceneBase* SceneUpdate(Input& input) = 0;

};