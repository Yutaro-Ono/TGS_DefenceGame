//-----------------------------------------------------------+
// タイトルシーン
//      : タイトル画面の処理
//                                  Last Update : 2019/07/10
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "SoundFX.h"
#include "Effect.h"

class SoundFX;
class PlayEffect;

class SceneTitle : public SceneBase
{

public:

	SceneTitle();
	~SceneTitle();

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera, Input& input, float deltaTime) override;

	void Draw() override;

	const int& GetNextScene() const { return toNext; };

private:

	int toNext;

	int m_alpha;                  // ロゴの透過表示用
	bool m_alphaCount;            // 透過処理用

	//--------------------------------------------------------------------------+
	// 画像ハンドル関係
	//--------------------------------------------------------------------------+
	int m_titleLogoGraph;         // タイトルロゴの画像ハンドル
	int m_titleLogoW, m_titleLogoH;

	PlayEffect* m_bgEffect;       // 背景のエフェクト
	SoundFX* m_bgm;               // タイトルで再生するBGM
};