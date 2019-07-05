//-----------------------------------------------------------+
// エネミーマネージャークラス
//      : エネミーの出現～消滅を管理するクラス
//                                  Last Update : 2019/07/03
//-----------------------------------------------------------+
#pragma once
#include <iostream>
#include <vector>
#include "DxLib.h"
#include "Common.h"
#include "Actor.h"
#include "Enemy.h"

class Actor;
class Enemy;

class EnemyManager final
{
public:

	void Initialize();                  // 各種初期化(モデルの読み込み、出現位置の設定)

	void Delete();                      // 各種解放処理

	void Update();                      // 更新処理

	void Draw();                        // 描画処理


private:

	int m_enemySourceHandle;            // エネミーモデルのハンドル

	std::vector<class Enemy*> enemy;          // エネミー


	static const int ENEMY_MAX_NUM;     // 敵の一度に出現する最大数
	static const int ENEMY_ALL_NUM;     // 敵の合計数

};
