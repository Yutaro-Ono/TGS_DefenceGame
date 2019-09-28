//-----------------------------------------------------------+
// アイテムマネージャークラス
//      : フィールド上にアイテムを追加・管理するクラス
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include <stdio.h>
#include <vector>
#include "Item.h"
#include "SceneInGame.h"
#include "Timer.h"

// クラス前方宣言
class Item;

class ItemManager final
{

public:

	ItemManager();                         // コンストラクタ
	~ItemManager();                        // デストラクタ

	void Initialize();                     // 初期化処理
	void Delete();                         // 解放処理

	void Update(float deltaTime);          // 更新処理

	void AddItem();                        // アイテムを追加する処理

	//-------------------------------------------------------------+
    // Getter/Setter関連
    //-------------------------------------------------------------+
	// ランダムな出現位置のゲッター
	const VECTOR& GetRandomPosition(const float sizeFieldX, const float sizeFieldZ) const;
	// 生成したアイテムごとのポインタを返す
	Item* GetItemPointer(int itemNum) { return m_item[itemNum]; }
	// 生成したアイテムの総数を返す
	const int& GetActiveItem()const { return (int)m_item.size(); }
	// 現在のフィールド上のアイテム個数ゲッター
	const int& GetItemOnField()const { return m_nowItem; }


private:

	int         m_sourceModelHandle;          // アイテムモデルのハンドル

	int                   m_nowItem;          // アイテムが何個出ているか

	std::vector<class Item*> m_item;          // アイテム

	static const int ITEM_START_NUM;          // 開始時のアイテムの数
	static const int ITEM_MAX;                // アイテムの最大数

};