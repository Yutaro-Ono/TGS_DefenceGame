//-----------------------------------------------------------------------+
// リザルトシーン                         
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+
#include "SceneResult.h"

SceneResult::SceneResult()
	:toNext(4)
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Initialize()
{
	m_bgm = new SoundFX("Data/Music/BGM/Result/cyrf_dreamland.mp3");
}

void SceneResult::Delete()
{
	m_bgm->Delete();
	delete (m_bgm);
}

void SceneResult::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM再生
	m_bgm->PlayLoopSoundFx();

	// STARTかENTERで次のシーンへ
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START))
	{
		m_bgm->StopSoundFx();
		toNext = 5;
	}
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		m_bgm->StopSoundFx();
		toNext = 5;
	}

	// BACKでシャットダウン
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_BACK))
	{
		GAME_INSTANCE.ShutDown();
	}
}

void SceneResult::Draw()
{
	if (m_clear == true)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "生き残れた");
	}
	if (m_clear == false)
	{
		DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2, GetColor(255, 255, 255), "生き残れなかった");
	}

	
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 50, GetColor(255, 255, 255), "STARTでリトライ");
	DrawFormatString(GAME_INSTANCE.GetScreenWidth() / 2, GAME_INSTANCE.GetScreenHeight() / 2 + 100, GetColor(255, 255, 255), "BACKで終了");
}
