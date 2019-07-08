//----------------------------------------------------------+
// プレイヤーマネージャークラス
//      : プレイヤーの更新はここで行う
//                                 Last Update : 2019/07/01
//----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Actor.h"
#include "Player.h"
class Actor;
class Player;

class PlayerManager final
{
public:
	
	PlayerManager();         // コンストラクタ
	~PlayerManager();        // デストラクタ

	void Initialize();       // プレイヤー初期化処理

	void Delete();           // 削除処理

	void Update(float deltaTime);           // 更新処理

	void Draw();             // 描画処理

	// 生成したプレイヤーへのポインタを取得する
	// 主にカメラの処理に用いる
	Player* GetPlayerPointer() { return m_player; }

private:

	int m_sourceModelHandle;      // モデルハンドル
	Player* m_player;              // プレイヤー



};