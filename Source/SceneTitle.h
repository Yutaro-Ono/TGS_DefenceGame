//-----------------------------------------------------------+
// タイトルシーン
//      : タイトル画面の処理
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "SceneBase.h"
#include "SoundFX.h"
#include "Effect.h"

// クラス前方宣言
class SoundFX;
class PlayEffect;

class SceneTitle : public SceneBase
{

public:

	SceneTitle();                                                                 // コンストラクタ
	~SceneTitle();                                                                // デストラクタ

	void Initialize() override;                                                   // 初期化処理
	void Delete() override;                                                       // 解放処理

	void Update(Camera& camera, Input& input, float deltaTime) override;          // 更新処理
	void Draw(TextGraph& title) override;                                         // 描画処理

	int SceneTransEffect(int in_alpha);                                           // シーン繊維のフェードエフェクト

	const bool& GetNextScene() const { return m_toNext; };                        // 次のシーンへ移行するフラグを返す
	SceneBase* SceneUpdate(Input& input) override;                                // 次のシーンへ移行する処理


private:

	bool m_toNext;                // 次のシーンへ移行するフラグ

	unsigned int m_logoAlpha;                  // ロゴの透過表示用
	unsigned int m_screenAlpha;                // 画面の透過表示用

	bool m_alphaCount;            // 透過処理用

	//--------------------------------------------------------------------------+
	// 画像ハンドル関係
	//--------------------------------------------------------------------------+
	int m_titleLogoGraph;            // タイトルロゴの画像ハンドル
	int m_titleLogoW;                // タイトルロゴ画像の横幅サイズ
	int m_titleLogoH;                // タイトルロゴ画像の縦幅サイズ

	PlayEffect* m_bgEffect;          // 背景のエフェクト
	SoundFX* m_bgm;                  // タイトルで再生するBGM
	SoundFX* m_enterSE;              // 決定音
	TextGraph* m_text;               // 描画用テキストフォント

};