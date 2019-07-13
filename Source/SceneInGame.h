//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�̃V�[���N���X
//      : �Q�[�����̑����I�ȏ����������ōs�� (�V�[�����N���X���p��)
//                                             Last Update : 2019/07/13
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

	void Initialize() override;                   // �e�평��������

	void Delete() override;                       // �e��������

	void SceneUpdate(SceneResult& result);        // �V�[���̍X�V����(��Ƀ��U���g�V�[���ւ̑J�ڏ���)

	void PlaceEnemyByTime();                      // ���Ԃ��ƂɃG�l�~�[��ǉ��z�u����֐�

	void Draw()override;                          // �`�揈��

	// �I�[�o�[���C�h�����X�V����(�s�v�Ȋ֐��̂��ߑ|���\��)
	void Update(Camera& camera, float deltaTime)override;

	// �X�V����
	void Update(Camera& camera, SceneResult& result, float deltaTime);

	//--------------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------------+
	// ���̃V�[��(���U���g)�ւ�enum��Ԃ�
	const int& GetNextScene() const { return toNext; }



private:

	int toNext;                                    // ���V�[���ւ̃n���h��

	int m_popCount;                                // �G�l�~�[�̏o���J�E���^�[

	PlayerManager* m_player;                       // �v���C���[
	EnemyManager* m_enemy;                         // �G�l�~�[
	InGameUIManager* m_UI;                         // UI
	ObjectManager* m_obj;                          // �I�u�W�F�N�g

};