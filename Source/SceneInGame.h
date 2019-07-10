//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�̃V�[���N���X
//      : �Q�[�����̑����I�ȏ����������ōs�� (�V�[�����N���X���p��)
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

	SceneInGame();                                // �R���X�g���N�^
	~SceneInGame();                               // �f�X�g���N�^

	void Initialize() override;

	void Delete() override;

	void Update(Input& input, Camera& camera, float deltaTime)override;

	void Draw()override;

private:

	int toNext;

	PlayerManager* m_player;           // �v���C���[

	EnemyManager* m_enemy;             // �G�l�~�[

	ObjectManager* m_obj;              // �I�u�W�F�N�g

	NpcManager* m_npc;                 // NPC

};