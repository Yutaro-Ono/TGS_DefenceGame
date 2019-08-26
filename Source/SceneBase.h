//-----------------------------------------------------------+
// �V�[�����N���X
//      : �e�V�[���̊��N���X�B���ʏ������s��
//                                  Last Update : 2019/07/01
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "TextGraph.h"

class Camera;
class Input;
class TextGraph;

class SceneBase
{
public:

	SceneBase();
	virtual ~SceneBase();

	virtual void Initialize() = 0;

	virtual void Delete() = 0;

	virtual void Update(Camera& camera, Input& input, float deltaTime) = 0;

	virtual void Draw(TextGraph& text) = 0;

	virtual SceneBase* SceneUpdate(Input& input) = 0;

protected:


};