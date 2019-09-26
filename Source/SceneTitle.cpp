//-----------------------------------------------------------------------+
// タイトルシーン                  
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "SceneTitle.h"
#include "Input.h"
#include "GameSystem.h"

// コンストラクタ
SceneTitle::SceneTitle()
	:m_toNext(false)
{
	// 処理なし
}

// デストラクタ
SceneTitle::~SceneTitle()
{
	// 処理なし
}

// 初期化処理
void SceneTitle::Initialize()
{
	// アルファ値を最大にしておく
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
	// 決定音
	m_enterSE = new SoundFX("Data/Music/SE/System/Enter/decision17.mp3");
}


// 解放処理
void SceneTitle::Delete()
{
	m_bgEffect->Delete();
	m_bgm->Delete();
	m_enterSE->Delete();

	delete (m_bgEffect);
	delete (m_bgm);
	delete (m_enterSE);
}

void SceneTitle::Update(Camera & camera, Input& input, float deltaTime)
{
	// BGM再生
	m_bgm->PlayLoopSoundFx();
}

// 描画処理
void SceneTitle::Draw(TextGraph& text)
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

	// ロゴの表示
	DrawGraph((GAME_INSTANCE.GetScreenWidth() / 2) - (m_titleLogoW / 2), (GAME_INSTANCE.GetScreenHeight() / 2 - 100) - (m_titleLogoH / 3), m_titleLogoGraph, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_alpha);              // ブレンドモード(透過)をオン
	// テキストの描画
	text.DrawTextMessage(680, 700, "PRESS START BUTTON");
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);                  //ブレンドモードをオフ

	// エフェクトの再生
	if (m_bgEffect->GetNowPlaying() == -1)
	{
		m_bgEffect->PlayEffekseer(VGet(700.0f, -150.0f, 0.0f));
		m_bgEffect->SetEffectScale(100.0f, 100.0f, 100.0f);
	}

}

// 次のシーンへの遷移処理 (シーン遷移条件がtrueだったら次シーンへのポインタを返し、falseだったらこのクラスのポインタを返す)
SceneBase * SceneTitle::SceneUpdate(Input& input)
{
	// STARTボタンかスペースキーで次のシーンへ
	if (input.GetPushButtonState(XINPUT_BUTTON::XINPUT_START) || CheckHitKey(KEY_INPUT_SPACE))
	{
		m_toNext = true;                    // 次シーンへ移動するフラグをオン
		m_enterSE->PlaySoundFx();           // 決定音を鳴らす
	}
	// 決定音の再生が終わったら解放し、次のシーンを返す
	if (m_toNext == true && m_enterSE->ScanNowPlaySound() == true)
	{
		m_bgm->StopSoundFx();               // BGMは止める
		return new SceneInGame();           // 次のシーンを返す
	}

	return this;
}
