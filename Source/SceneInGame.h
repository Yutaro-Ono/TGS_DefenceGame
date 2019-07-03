//----------------------------------------------------------------------+
// inゲーム(ゲーム中)のシーンクラス
//      : ゲーム中の総合的な処理をここで行う (シーン基底クラスを継承)
//                                             Last Update : 2019/07/01
//----------------------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "SceneBase.h"
#include "PlayerManager.h"
#include "ObjectManager.h"
#include "Camera.h"

class SceneBase;
class PlayerManager;
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

	void Update(Camera& camera)override;

	void Draw()override;

private:

	PlayerManager* m_player;           // プレイヤー

	ObjectManager* m_obj;              // オブジェクト

};