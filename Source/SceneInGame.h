//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�̃V�[���N���X
//      : �Q�[�����̑����I�ȏ����������ōs�� (�V�[�����N���X���p��)
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

	SceneInGame();                                // �R���X�g���N�^
	~SceneInGame();                               // �f�X�g���N�^

	void Initialize() override;

	void Delete() override;

	void Update(Input& input, Camera& camera, float deltaTime)override;

	void Update(Input& input, Camera& camera, SceneResult& result, float deltaTime);

	void SceneUpdate(SceneResult& result);

	void Draw()override;

	const int& GetNextScene() const { return toNext; }             // ���̃V�[����enum��Ԃ�

private:

	int toNext;



	PlayerManager* m_player;           // �v���C���[

	EnemyManager* m_enemy;             // �G�l�~�[

	InGameUIManager* m_UI;             // UI

	ObjectManager* m_obj;              // �I�u�W�F�N�g

};