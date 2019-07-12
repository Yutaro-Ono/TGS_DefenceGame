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
#include "Timer.h"

class Actor;
class Enemy;
class Timer;

class EnemyManager final
{
public:

	void Initialize();                  // 各種初期化(モデルの読み込み、出現位置の設定)

	void Delete();                      // 各種解放処理

	void Update(PlayerManager& playerManager, float deltaTime);                      // 更新処理

	void Draw();                        // 描画処理

	void AddEnemy();                    // エネミーを追加する

	// 生成したエネミーごとのポインタを取得する
	Enemy* GetEnemyPointer(int enemyNum) { return m_enemy[enemyNum]; }
	//// アクティブなエネミーの数を返す
	const int& GetActiveEnemy() const { size_t e_max; int num; e_max = m_enemy.size(); num = (int)e_max; return num; }

private:

	int m_enemySourceHandle;            // エネミーモデルのハンドル

	std::vector<class Enemy*> m_enemy;          // エネミー


	static const int ENEMY_MAX_NUM;     // 敵の一度に出現する最大数
	static const int ENEMY_ALL_NUM;     // 敵の合計数

};
