//-----------------------------------------------------------------------+
// リザルトシーン                         
//                                              Last Update : 2019/09/03
//-----------------------------------------------------------------------+
#include "SceneResult.h"

#pragma warning(disable:4996)

SceneResult::SceneResult(bool in_isGameOver, int in_score)
	:toNext(4)
{
	// ゲームをクリアしたかどうか
	m_gameOver = in_isGameOver;
	// スコアを格納
	m_score = in_score;
}

SceneResult::~SceneResult()
{
}

// 各種初期化処理
void SceneResult::Initialize()
{
	m_bgm = new SoundFX("Data/Music/BGM/Result/cyrf_dreamland.mp3");
}

// 各種解放処理
void SceneResult::Delete()
{
	m_bgm->Delete();
	delete (m_bgm);
}

// 更新処理
void SceneResult::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM再生
	m_bgm->PlayLoopSoundFx();
}

// 描画処理
void SceneResult::Draw(TextGraph& text)
{
	char score[20];
	sprintf(score, "SCORE : %d", m_score);


	// ゲームオーバーかどうかで処理を分岐
	if (m_gameOver == false)
	{
		text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, "Game Clear !!");
		// スコアを表示
		text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 50, score);
	}
	if (m_gameOver == true)
	{
		text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, "Game Over ...");
	}

	// リトライ,終了のチュートリアル
	text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 140, "START : Retry");
	text.DrawTextMessage(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 175, "ESCAPE : GAME END");
}

// シーンの更新処理
SceneBase * SceneResult::SceneUpdate(Input & input)
{
	// STARTかENTERで次のシーンへ
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START) || CheckHitKey(KEY_INPUT_RETURN))
	{
		m_bgm->StopSoundFx();       // 音楽を停止
		Delete();                   // 解放処理

		// 次のシーンを返す
		return new SceneTitle();
	}

	// BACKで終了
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_BACK))
	{
		Delete();                     // 解放処理

		GAME_INSTANCE.SetGameQuit(true);      // ゲームを抜ける
	}

	// 条件が揃わなければ自身のポインタを返す
	return this;
}
