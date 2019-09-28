//----------------------------------------------------------+
// プレイヤーマネージャークラス
//      : プレイヤーの更新はここで行う
//                                         2019 Yutaro Ono.
//----------------------------------------------------------+
#pragma once

// インクルードファイル
#include "DxLib.h"
#include "Input.h"
#include "Actor.h"
#include "Player.h"

// クラス前方宣言
class Input;
class Actor;
class Player;

class PlayerManager final
{

public:
	
	enum PLAYER_STATE
	{
		ACTIVE = 0,
		DEAD,
	};

	PlayerManager(int in_playerNum);                     // コンストラクタ(プレイヤー番号を代入)
	~PlayerManager();                                    // デストラクタ

	void Initialize();                                   // プレイヤー初期化処理
	void Delete();                                       // 削除処理

	void Update(Input& input, float deltaTime);          // 更新処理
	void Draw();                                         // 描画処理

	//--------------------------------------------------------------------------+
	// Getter/Setter 関連
	//--------------------------------------------------------------------------+
	// プレイヤーの状態を取得する
	const int& GetPlayerState() { return m_playerState; }
	// 生成したプレイヤーへのポインタを取得する
	// 主にカメラの処理に用いる
	Player* GetPlayerPointer() { return m_player; }


private:

	int             m_playerNum;          // プレイヤーの番号(1P, 2P, 3P, 4P)
	int           m_playerState;          // プレイヤーの状態格納

	int     m_sourceModelHandle;          // モデルハンドル

	Player            *m_player;          // プレイヤー

};