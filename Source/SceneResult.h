//-----------------------------------------------------------+
// リザルトシーン
//      : リザルト画面での処理
//                                  Last Update : 2019/09/03
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "GameSystem.h"
#include "SoundFX.h"

class SoundFX;

class SceneResult : public SceneBase
{
public:

	SceneResult(bool in_isGameOver, int in_score);
	~SceneResult();

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera, Input& input, float deltaTime) override;

	void Draw(TextGraph& text) override;

	void SetScore(const int score) { m_score = score; }          // スコアのセッター

	SceneBase* SceneUpdate(Input& input) override;

private:

	int toNext;                    // 次のシーンへのフラグ

	int m_score;                   // スコア

	bool m_gameOver;               // ゲームクリアかゲームオーバーか判定するフラグ

	SoundFX* m_bgm;                // BGM再生用

};