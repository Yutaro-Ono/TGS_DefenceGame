//-----------------------------------------------------------+
// リザルトシーン
//      : リザルト画面での処理
//                                         2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "SceneBase.h"
#include "GameSystem.h"
#include "SoundFX.h"

// クラス前方宣言
class SoundFX;

class SceneResult : public SceneBase
{

public:

	SceneResult(bool in_isGameOver, int in_score);                                // コンストラクタ
	~SceneResult();                                                               // デストラクタ

	void Initialize() override;                                                   // 初期化処理
	void Delete() override;                                                       // 解放処理

	void Update(Camera& camera, Input& input, float deltaTime) override;          // 更新処理
	void Draw(TextGraph& text) override;                                          // 描画処理

	//--------------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------------+
	// スコアのセッター
	void SetScore(const int score) { m_score = score; }
	// シーンが更新されたかどうかを取得
	SceneBase* SceneUpdate(Input& input) override;


private:

	int          toNext;          // 次のシーンへのフラグ
	int         m_score;          // スコア
	bool     m_gameOver;          // ゲームクリアかゲームオーバーか判定するフラグ

	SoundFX*      m_bgm;          // BGM再生用

};