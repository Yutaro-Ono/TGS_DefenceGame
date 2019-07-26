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

	// アイテムの初期座標セット(ランダム)
	for (auto item : m_item)
	{
		item->SetEmergence(GetRandomPosition());
	}
}

// 解放処理
void ItemManager::Delete()
{
	// アイテムの削除
	while (!m_item.empty())
	{
		delete m_item.back();
	}
	m_item.clear();
}

// 更新処理
void ItemManager::Update(float deltaTime)
{
	// アイテムの更新処理
	for (auto item : m_item)
	{
		// 出現状態なら落下させる
		if (item->GetState() == Item::POP)
		{
			item->Fall(deltaTime);
		}

		// アクティブ状態ならアップデート
		if (item->GetState() == Item::ACTIVE)
		{
			item->Update();
		}
	}
}

// 描画処理
void ItemManager::Draw()
{
	// アイテムの描画処理
	for (auto item : m_item)
	{
		item->Draw();
	}
}

// フィールドへのアイテム追加
void ItemManager::AddItem()
{
	// フィールド上のアイテムの総数が最大値より少なかったら
	if (m_numOnField < ITEM_MAX)
	{
		// 追加
		m_item.emplace_back(new Item(m_sourceModelHandle));

		// 出現位置の設定(ランダム)
		m_item.back()->SetEmergence(GetRandomPosition());
	}

}

// ランダムな出現位置のゲッター
const VECTOR & ItemManager::GetRandomPosition() const
{
	VECTOR randPos;



	return randPos;
}
