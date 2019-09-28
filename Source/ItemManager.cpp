//-----------------------------------------------------------------------+
// アイテムマネージャークラス           
//                                                      2019 Yutaro Ono.
//-----------------------------------------------------------------------+

// インクルードファイル
#include "ItemManager.h"

const int ItemManager::ITEM_START_NUM = 3;       // 開始時のアイテム総数
const int ItemManager::ITEM_MAX = 150;            // アイテムの最大数

// コンストラクタ
ItemManager::ItemManager()
	:m_sourceModelHandle(-1)
{
	// 処理なし
}

// デストラクタ
ItemManager::~ItemManager()
{
	// 処理なし
}

// 初期化処理
void ItemManager::Initialize()
{

	// モデルのロード
	m_sourceModelHandle = MV1LoadModel("Data/Model/Item/Score/20facestar.mv1");

	// エラー表記
	if (m_sourceModelHandle == -1)
	{
		printfDx("モデルロード失敗 : アイテム");
	}

	// 初期アイテムの生成
	for (int i = 0; i < ITEM_START_NUM; i++)
	{
		m_item.emplace_back(new Item(m_sourceModelHandle));
	}

	// アイテムの初期座標セット(ランダム)
	for (auto item : m_item)
	{
		item->Initialize();
		item->SetEmergence(GetRandomPosition(90.0f, 85.0f));
	}

	// フィールド上のアイテムを初期化
	m_nowItem = 0;
}

// 解放処理
void ItemManager::Delete()
{
	// モデルの削除
	MV1DeleteModel(m_sourceModelHandle);

	// アイテムの削除
	while (!m_item.empty())
	{
		delete m_item.back();
		m_item.pop_back();
	}
	// アイテムベクトルのクリア
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
			item->Update(deltaTime);
			item->Draw();
		}

		// アクティブ状態ならアップデート
		if (item->GetState() == Item::ACTIVE)
		{
			item->Update(deltaTime);
			item->Draw();
		}

		// ディアクティブ状態なら
		if (item->GetState() == Item::DEACTIVE)
		{

		}

		// 回収されたら現在のフィールド上のアイテムを減算し、消す
		if (item->GetState() == Item::DEAD)
		{
			// フィールド上のアイテムを減らす
			m_nowItem--;
			// アイテムの消去
			m_item.clear();
		}
	}
}

// フィールドへのアイテム追加
void ItemManager::AddItem()
{
	// フィールド上のアイテムの総数が最大値より少なかったら
	if (m_item.size() < ITEM_MAX)
	{
		// 最後尾に生成
		m_item.emplace_back(new Item(m_sourceModelHandle));
		// 生成したアイテムの初期化
		m_item.back()->Initialize();
		// 出現位置の設定(ランダム)
		m_item.back()->SetEmergence(GetRandomPosition(90.0f, 85.0f));

		// フィールド上のアイテムを更新
		m_nowItem++;
	}
}

// ランダムな出現位置のゲッター
const VECTOR & ItemManager::GetRandomPosition(const float sizeFieldX, const float sizeFieldZ) const
{
	VECTOR randPos = VGet(0.0f, 100.0f, 0.0f);

	// X座標のポジション設定
	randPos.x = GetRand(sizeFieldX);
	// 回収ポッドと被らないように位置調整
	if (randPos.x <= 10.0f)
	{
		randPos.x += 10.0f;
	}

	// Z座標のポジション設定
	randPos.z = GetRand(sizeFieldZ);
	// 回収ポッドと被らないように位置調整
	if (randPos.z <= 15.0f)
	{
		randPos.z += 15.0f;
	}

	// X座標の正負設定
	if (GetRand(1) == 0)
	{
		randPos.x *= -1.0f;
	}
	// Z座標の正負設定
	if (GetRand(1) == 0)
	{
		randPos.z *= -1.0f;
	}

	// ランダムなポジションを返す
	return randPos;
}
