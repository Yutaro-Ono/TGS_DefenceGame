//-----------------------------------------------------------------------+
// アイテムマネージャークラス           
//                                              Last Update : 2019/07/25
//-----------------------------------------------------------------------+
#include "ItemManager.h"

const int ItemManager::ITEM_MAX = 3;        // アイテムの最大数

// コンストラクタ
ItemManager::ItemManager()
{
}

// デストラクタ
ItemManager::~ItemManager()
{
}


// 初期化処理
void ItemManager::Initialize()
{
	// フィールド上のアイテム数を初期化
	m_numOnField = 0;

	// モデルのロード
	m_sourceModelHandle = MV1LoadModel("Data/Model/Item/Score/20facestar.mv1");

	// 初期アイテムの生成
	for (int i = 0; i < ITEM_MAX; i++)
	{
		m_item.emplace_back(new Item(m_sourceModelHandle));
		m_numOnField++;
	}

}

// 解放処理
void ItemManager::Delete()
{

}

// 更新処理
void ItemManager::Update()
{
	// アイテムの更新処理
	for (auto item : m_item)
	{
		item->Update();
	}


}

// 描画処理
void ItemManager::Draw()
{
}

// フィールドへのアイテム追加
void ItemManager::AddItem()
{
}
