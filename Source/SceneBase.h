//-----------------------------------------------------------+
// シーン基底クラス
//      : 各シーンの基底クラス。共通処理を行う
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"

class Camera;

class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase();

	virtual void Initialize() = 0;

	virtual void Delete() = 0;

	virtual void Update(Camera& camera) = 0;

	virtual void Draw() = 0;

protected:

	bool toNextScene;

};