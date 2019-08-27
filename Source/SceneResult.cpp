//-----------------------------------------------------------------------+
// リザルトシーン                         
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+
#include "SceneResult.h"

SceneResult::SceneResult(bool in_isGameOver)
	:toNext(4)
{
	// ゲームをクリアしたかどうか
	m_gameOver = in_isGameOver;
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
	// ゲームオーバーかどうかで処理を分岐
	if (m_gameOver == false)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "生き残れた");
	}
	if (m_gameOver == true)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "生き残れなかった");
	}

	// リトライ,終了のチュートリアル
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 50, GetColor(255, 255, 255), "STARTでリトライ");
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 100, GetColor(255, 255, 255), "ESCAPEで終了");
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
		Delete();

		GAME_INSTANCE.SetGameQuit(true);
	}

	// 条件が揃わなければ自身のポインタを返す
	return this;
}
