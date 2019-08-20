//-----------------------------------------------------------------------+
// タイトルシーン                  
//                                              Last Update : 2019/07/11
//-----------------------------------------------------------------------+

#include "SceneTitle.h"
#include "Input.h"
#include "GameSystem.h"

SceneTitle::SceneTitle()
	:toNext(1)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Initialize()
{
	// タイトルロゴ画像をロード、サイズ取得
	m_titleLogoGraph = LoadGraph("Data/Interface/Title_Logo_2.png");
	// タイトルロゴの画像サイズを取得
	GetGraphSize(m_titleLogoGraph, &m_titleLogoW, &m_titleLogoH);
	// 再生するBGM
	m_bgm = new SoundFX("Data/Music/BGM/Title/cyrf_lu_main_theme.mp3");
}

void SceneTitle::Delete()
{
	m_bgm->Delete();
	delete (m_bgm);
}

void SceneTitle::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM再生
	m_bgm->PlayLoopSoundFx();

	// Aボタンで次のシーンへ
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START))
	{
		m_bgm->StopSoundFx();
		toNext = 3;
	}

	// スペースボタンで次のシーンへ
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		m_bgm->StopSoundFx();
		toNext = 3;
	}
	

	//描画
	Draw();
}

void SceneTitle::Draw()
{
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 50, "UFOから制限時間逃げ回れ！", GetColor(255, 255, 255));
	
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 100, "SPACEキーでスタート", GetColor(255, 255, 255));

}
