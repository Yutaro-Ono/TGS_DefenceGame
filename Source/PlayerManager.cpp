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
	,m_playerState(PLAYER_STATE::ACTIVE)
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
	m_sourceModelHandle = MV1LoadModel("Data/Model/Actor/Player/humster/model/humster.mv1");	
	// モデルのロード失敗時に表示
	if (m_sourceModelHandle <= -1)
	{
		printfDx("Player : モデル読み込み失敗\n");
	}
	// プレイヤー生成
	m_player = new Player(m_sourceModelHandle);
	// 初期化
	m_player->Initialize();
}

// 各種解放処理
void PlayerManager::Delete()
{
}

// 更新処理
void PlayerManager::Update(float deltaTime)
{
	// プレイヤーの更新
	m_player->Update(deltaTime);

	// プレイヤーの体力が0になったら死亡状態にする
	if (m_player->GetHitPoint() <= 0)
	{
		m_playerState = PLAYER_STATE::DEAD;
	}
}

// 描画処理
void PlayerManager::Draw()
{
	m_player->Draw();
}
