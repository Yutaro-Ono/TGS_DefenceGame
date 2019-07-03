//-----------------------------------------------------------------------+
// NPCマネージャークラス                                    
//                                              Last Update : 2019/07/02
//-----------------------------------------------------------------------+
#include "NpcManager.h"

// コンストラクタ
NpcManager::NpcManager()
{
}

// デストラクタ
NpcManager::~NpcManager()
{
}

// 各種初期化処理
void NpcManager::Initialize()
{
	// アイドルモデルをロード
	m_idolSourceHandle = MV1LoadModel("Data/Model/Actor/Idol/宮崎しおん/miyazaki_shion.mv1");
	// アイドルを生成
	m_idol = new Idol(m_idolSourceHandle);
}

// 各種解放処理
void NpcManager::Delete()
{
	MV1DeleteModel(m_idolSourceHandle);
	delete (m_idol);
}

// 更新処理
void NpcManager::Update()
{
	// アイドルの更新
	m_idol->Update();
}

// 描画処理
void NpcManager::Draw()
{
	// アイドルの描画
	m_idol->Draw();
}
