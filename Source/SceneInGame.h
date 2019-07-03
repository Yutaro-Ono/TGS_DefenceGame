//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�̃V�[���N���X
//      : �Q�[�����̑����I�ȏ����������ōs�� (�V�[�����N���X���p��)
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

	SceneInGame();                                // �R���X�g���N�^
	~SceneInGame();                               // �f�X�g���N�^

	void Initialize() override;

	void Delete() override;

	void Update(Camera& camera)override;

	void Draw()override;

private:

	PlayerManager* m_player;           // �v���C���[

	ObjectManager* m_obj;              // �I�u�W�F�N�g

};