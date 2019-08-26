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
	m_alpha = 255;
	m_alphaCount = false;
	// タイトルロゴ画像をロード、サイズ取得
	m_titleLogoGraph = LoadGraph("Data/Interface/Title_Logo_2.png");
	// タイトルロゴの画像サイズを取得
	GetGraphSize(m_titleLogoGraph, &m_titleLogoW, &m_titleLogoH);
	// 背景のエフェクト
	m_bgEffect = new PlayEffect("Data/Effects/UI_BgStarDust.efk");
	m_bgEffect->Initialize();
	// 再生するBGM
	m_bgm = new SoundFX("Data/Music/BGM/Title/cyrf_lu_main_theme.mp3");

	m_text = new TextGraph();
	m_text->Initialize();
}

void SceneTitle::Delete()
{
	m_bgEffect->Delete();
	m_bgm->Delete();

	m_text->Delete();

	delete (m_bgEffect);
	delete (m_bgm);

	delete (m_text);
}

void SceneTitle::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM再生
	m_bgm->PlayLoopSoundFx();

}

void SceneTitle::Draw()
{

	if (m_alpha >= 255)
	{
		m_alphaCount = false;
	}
	if (m_alpha <= 32)
	{
		m_alphaCount = true;
	}

	if (m_alphaCount == true)
	{
		m_alpha += 2;
	}
	if (m_alphaCount == false)
	{
		m_alpha -= 2;
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);       // ブレンドモード(透過)をオン
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);           //ブレンドモードをオフ

	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 700, GAME_INSTANCE.GetScreenHeight() / 2 + 50, "できるだけ多くの星を集めて中心のポッドへ持っていこう！", GetColor(255, 255, 255));
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 250, GAME_INSTANCE.GetScreenHeight() / 2 + 100, "UFOに当たるとダメージ！", GetColor(255, 255, 255));
	DrawString(GAME_INSTANCE.GetScreenWidth() / 2 - 350, GAME_INSTANCE.GetScreenHeight() / 2 + 250, "STARTボタンorSPACEキーでスタート", GetColor(255, 255, 255));

	// エフェクトの再生
	if (m_bgEffect->GetNowPlaying() == -1)
	{
		m_bgEffect->PlayEffekseer(VGet(700.0f, -150.0f, 0.0f));
		m_bgEffect->SetEffectScale(100.0f, 100.0f, 100.0f);
	}

	m_text->DrawTextMessage(0, 100, "PRESS ANY KEY");

	// Effekseerの更新
	UpdateEffekseer3D();
	// Effekseerの描画
	DrawEffekseer3D();
}

// 次のシーンへの遷移処理 (シーン遷移条件がtrueだったら次シーンへのポインタを返し、falseだったらこのクラスのポインタを返す)
SceneBase * SceneTitle::SceneUpdate(Input& input)
{
	// STARTボタンかスペースキーで次のシーンへ
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START) || CheckHitKey(KEY_INPUT_SPACE))
	{
		m_bgm->StopSoundFx();
		Delete();                         // 解放処理

		return new SceneInGame();           // 次のシーンを返す
	}

	return this;
}
