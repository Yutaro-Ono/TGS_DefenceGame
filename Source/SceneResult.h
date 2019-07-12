//-----------------------------------------------------------+
// リザルトシーン
//      : リザルト画面での処理
//                                  Last Update : 2019/07/11
//-----------------------------------------------------------+
#pragma once
#include "SceneBase.h"
#include "GameSystem.h"

class SceneResult : public SceneBase
{
public:

	SceneResult();
	~SceneResult();

	void Initialize() override;

	void Delete() override;

	void Update(Input& input, Camera& camera, float deltaTime) override;

	void Draw() override;

	void SetScore(const int score) { m_score = score; }          // スコアのセッター

	const int& GetNextScene() const { return toNext; }           // 次のシーンへのセッター

	void SetClear(const bool clear) { m_clear = clear; }

private:

	int toNext;

	int m_score;

	bool m_clear;           // ゲームクリアかゲームオーバーか判定するフラグ

};