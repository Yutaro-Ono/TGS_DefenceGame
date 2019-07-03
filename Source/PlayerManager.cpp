//-----------------------------------------------------------------------+
// プレイヤーマネージャークラス                                 
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "DxLib.h"
#include "PlayerManager.h"
#include "Actor.h"
#include "Player.h"

// コンストラクタ
PlayerManager::PlayerManager()
	:m_sourceModelHandle(-1)
{
	m_player = NULL;
}

// デストラクタ
PlayerManager::~PlayerManager()
{
	MV1DeleteModel(m_sourceModelHandle);      // モデルの削除
	delete(m_player);
}

// プレイヤーモデル生成処理
void PlayerManager::Initialize()
{
	// モデルを読み込み
	m_sourceModelHandle = MV1LoadModel("Data/Model/Actor/Player/けんもうくん改/けんもうくん改.pmx");	
	
	if (m_sourceModelHandle <= -1)
	{
		printfDx("Player : モデル読み込み失敗\n");
	}

	m_player = new Player(m_sourceModelHandle);
}

// 各種解放処理
void PlayerManager::Delete()
{
}

// 更新処理
void PlayerManager::Update()
{
	m_player->Update();
	// ポジションをセット
	MV1SetPosition(m_sourceModelHandle, VGet(0.0f, 0.0f, 0.0f));

}

// 描画処理
void PlayerManager::Draw()
{
	m_player->Draw();


}
