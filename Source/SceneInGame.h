//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�̃V�[���N���X
//      : �Q�[�����̑����I�ȏ����������ōs�� (�V�[�����N���X���p��)
//                                                     2019 Yutaro Ono.
//----------------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "SceneBase.h"
#include "SceneResult.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include "ObjectManager.h"
#include "InGameUIManager.h"
#include "DirectorCountDown.h"
#include "Camera.h"
#include "Timer.h"
#include "SoundFX.h"

// �N���X�O���錾
class SceneBase;
class SceneResult;
class PlayerManager;
class EnemyManager;
class ItemManager;
class InGameUIManager;
class ObjectManager;
class Player;
class CountDown;
class Camera;
class Timer;
class SoundFX;

class SceneInGame : public SceneBase
{

public:

	// �Q�[���V�[�����̃t�F�[�Y
	enum GAME_PHASE
	{
		START_COUNTDOWN,
		IN_GAME,
		INTERVAL,
	};

	SceneInGame();                                                                // �R���X�g���N�^
	~SceneInGame();                                                               // �f�X�g���N�^

	void Initialize() override;                                                   // �e�평��������

	void Delete() override;                                                       // �e��������

	void Draw(TextGraph& text) override;                                          // �`�揈��

	void Update(Camera& camera, Input& input, float deltaTime) override;          // �X�V����

	void PlaceEnemyByTime();                                                      // ���Ԃ��ƂɃG�l�~�[��ǉ��z�u����֐�

	//--------------------------------------------------------------------------------+
	// Getter/Setter �֘A
	//--------------------------------------------------------------------------------+
	// �V�[�����X�V���ꂽ���ǂ����̎擾
	SceneBase* SceneUpdate(Input& input) override;


private:

	int                  toNext;          // ���V�[���ւ̃n���h��
	int              m_popCount;          // �G�l�~�[�̏o���J�E���^�[

	bool             m_setTimer;          // �Q�[���V�[���N�����A�^�C�}�[�̃Z�b�g�t���O

	bool            m_startGame;          // ���̃t���O����������Q�[�����J�n����
	bool              m_isClear;          // �Q�[�����N���A�������ǂ���
	bool           m_isGameOver;          // �Q�[���I�[�o�[�ɂȂ������ǂ���   

	Timer*              m_timer;          // �^�C�}�[
	PlayerManager*     m_player;          // �v���C���[
	EnemyManager*       m_enemy;          // �G�l�~�[
	ItemManager*         m_item;          // �A�C�e��
	InGameUIManager*       m_UI;          // UI
	ObjectManager*        m_obj;          // �I�u�W�F�N�g
	SoundFX*              m_bgm;          // BGM
	CountDown*      m_countdown;          // �J�E���g�_�E�����o

	static const int     MAX_GAME_TIME;       // �Q�[����������

};