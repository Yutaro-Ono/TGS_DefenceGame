//-----------------------------------------------------------+
// アイテムマネージャークラス
//      : フィールド上にアイテムを追加・管理するクラス
//                                  Last Update : 2019/07/25
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include <stdio.h>
#include <vector>
#include "Item.h"
#include "SceneInGame.h"
#include "Timer.h"

class Item;

class ItemManager final
{
public:

	ItemManager();
	~ItemManager();

	void Initialize();

	void Delete();

	void Update(float deltaTime);

	void AddItem();

	// ランダムな出現位置のゲッター
	const VECTOR& GetRandomPosition(const float sizeFieldX, const float sizeFieldZ) const;
	// 生成したアイテムごとのポインタを返す
	Item* GetItemPointer(int itemNum) { return m_item[itemNum]; }
	// 生成したアイテムの総数を返す
	const int& GetActiveItem()const { return (int)m_item.size(); }

private:

	int m_sourceModelHandle;                 // アイテムモデルのハンドル

	std::vector<class Item*> m_item;         // アイテム

	static const int ITEM_START_NUM;         // 開始時のアイテムの数
	static const int ITEM_MAX;               // アイテムの最大数

};