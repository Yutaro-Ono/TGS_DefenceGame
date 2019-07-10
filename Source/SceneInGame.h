//----------------------------------------------------------------------+
// inゲーム(ゲーム中)のシーンクラス
//      : ゲーム中の総合的な処理をここで行う (シーン基底クラスを継承)
//                                             Last Update : 2019/07/02
//----------------------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "SceneBase.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ObjectManager.h"
#include "NpcManager.h"
#include "Camera.h"

class SceneBase;
class PlayerManager;
class EnemyManager;
class ObjectManager;
class Player;
class Camera;

class SceneInGame : public SceneBase
{
public:

	SceneInGame();                                // コンストラクタ
	~SceneInGame();                               // デストラクタ

	void Initialize() override;

	void Delete() override;

	void Update(Input& input, Camera& camera, float deltaTime)override;

	void Draw()override;

private:

	int toNext;

	PlayerManager* m_player;           // プレイヤー

	EnemyManager* m_enemy;             // エネミー

	ObjectManager* m_obj;              // オブジェクト

	NpcManager* m_npc;                 // NPC

};