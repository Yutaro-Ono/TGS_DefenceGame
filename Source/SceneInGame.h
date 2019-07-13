//----------------------------------------------------------------------+
// inゲーム(ゲーム中)のシーンクラス
//      : ゲーム中の総合的な処理をここで行う (シーン基底クラスを継承)
//                                             Last Update : 2019/07/02
//----------------------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "SceneBase.h"
#include "SceneResult.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ObjectManager.h"
#include "InGameUIManager.h"
#include "Camera.h"
#include "Timer.h"

class SceneBase;
class SceneResult;
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

	void Update(Input& input, Camera& camera, SceneResult& result, float deltaTime);

	void SceneUpdate(SceneResult& result);

	void Draw()override;

	const int& GetNextScene() const { return toNext; }             // 次のシーンのenumを返す

private:

	int toNext;



	PlayerManager* m_player;           // プレイヤー

	EnemyManager* m_enemy;             // エネミー

	InGameUIManager* m_UI;             // UI

	ObjectManager* m_obj;              // オブジェクト

};