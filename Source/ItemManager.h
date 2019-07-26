//-----------------------------------------------------------+
// アイテムマネージャークラス
//      : フィールド上にアイテムを追加・管理するクラス
//                                  Last Update : 2019/07/25
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include <vector>
#include "Item.h"

class Item;

class ItemManager final
{
public:

	ItemManager();
	~ItemManager();

	void Initialize();

	void Delete();

	void Update(float deltaTime);

	void Draw();

	void AddItem();

	// ランダムな出現位置のゲッター
	const VECTOR& GetRandomPosition() const;

private:

	int m_sourceModelHandle;                 // アイテムモデルのハンドル

	std::vector<class Item*> m_item;         // アイテム

	int m_numOnField;                        // 現在のフィールド上にあるアイテムの総数

	static const int ITEM_MAX;               // アイテムの最大数

};