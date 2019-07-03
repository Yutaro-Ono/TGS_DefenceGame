//----------------------------------------------------------------------+
// inゲーム(ゲーム中)シーン                               
//                                              Last Update : 2019/07/01
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "PlayerManager.h"
#include "Camera.h"

// コンストラクタ
SceneInGame::SceneInGame()
{
	m_player = NULL;
}

// デストラクタ
SceneInGame::~SceneInGame()
{
}

// 各種初期化処理
void SceneInGame::Initialize()
{
	m_player = new PlayerManager();
	m_player->Initialize();

	m_obj = new ObjectManager();
	m_obj->Initialize();
}

// 各種解放処理
void SceneInGame::Delete()
{
	delete (m_player);
	delete (m_obj);
}

// 更新処理
void SceneInGame::Update(Camera& camera)
{
	camera.Update(*m_player);
	m_player->Update();
}

// 描画処理
void SceneInGame::Draw()
{
	// プレイヤーの描画
	m_player->Draw();
	// オブジェクトの描画
	m_obj->Draw();
}
