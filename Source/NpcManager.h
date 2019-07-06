//-----------------------------------------------------------+
// NPCマネージャークラス
//      : NPC関連(非敵対)の総合的な処理を行う
//                                  Last Update : 2019/07/02
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Idol.h"

class NpcManager final
{
public:
	NpcManager();                 // コンストラクタ
	~NpcManager();                // デストラクタ      

	void Initialize();            // 各種初期化

	void Delete();                // 各種解放処理

	void Update(float deltaTime);                // 更新

	void Draw();                  // 描画

private:

	int m_idolSourceHandle;        // アイドルのモデルハンドル

	Actor* m_idol;                 // アイドル
};