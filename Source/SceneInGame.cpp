//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�V�[��                               
//                                              Last Update : 2019/07/12
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "Timer.h"
#include "PlayerManager.h"
#include "Camera.h"
#include "HitChecker.h"

class Timer;

// �R���X�g���N�^
SceneInGame::SceneInGame()
{
	m_player = NULL;
	m_enemy = NULL;
	toNext = 3;
}

// �f�X�g���N�^
SceneInGame::~SceneInGame()
{
}

// �e�평��������
void SceneInGame::Initialize()
{
	// �v���C���[�𐶐��C������
	m_player = new PlayerManager();
	m_player->Initialize();
	// �G�l�~�[�𐶐��C������
	m_enemy = new EnemyManager();
	m_enemy->Initialize();
	// UI�𐶐��A������
	m_UI = new InGameUIManager();
	m_UI->Initialize();
	// �I�u�W�F�N�g�𐶐��C������
	m_obj = new ObjectManager();
	m_obj->Initialize();

	TIMER_INSTANCE.Initialize();
	m_popCount = 0;
}

// �e��������
void SceneInGame::Delete()
{
	delete (m_player);
	delete (m_enemy);
	delete (m_obj);
	delete (m_UI);
}

// �I�[�o�[���C�h�����A�b�v�f�[�g(�����Ȃ�)
void SceneInGame::Update(Input & input, Camera & camera, float deltaTime)
{
}

// �X�V����
void SceneInGame::Update(Input& input, Camera& camera, SceneResult& result, float deltaTime)
{

	// �L�[�̉�����ԃ`�F�b�N
	input.KeyChecker();

	// �J�����̍X�V
	camera.Update(*m_player);

	// �����蔻�菈��
	HitChecker::CheckHit(*m_player, *m_enemy);

	for (int i = 0; i < m_enemy->GetActiveEnemy(); i++)
	{
		HitChecker::CheckHitEnemy(*m_enemy, i);
	}

	// �v���C���[�̍X�V
	m_player->Update(input, deltaTime);
	// �G�l�~�[�̍X�V
	m_enemy->Update(*m_player, deltaTime);

	// �c�莞�Ԃɂ���ăG�l�~�[��ǉ�
	if (TIMER_INSTANCE.GetTimer() == 50 && m_popCount == 0)
	{
		m_enemy->AddEnemy();
		m_popCount = 1;
	}
	if (TIMER_INSTANCE.GetTimer() == 45 && m_popCount == 1)
	{
		m_enemy->AddEnemy();
		m_popCount = 2;
	}
	if (TIMER_INSTANCE.GetTimer() == 40 && m_popCount == 2)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 3;
	}
	if (TIMER_INSTANCE.GetTimer() == 35 && m_popCount == 3)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 4;
	}
	if (TIMER_INSTANCE.GetTimer() == 30 && m_popCount == 4)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 5;
	}
	if (TIMER_INSTANCE.GetTimer() == 25 && m_popCount == 5)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 6;
	}
	if (TIMER_INSTANCE.GetTimer() == 20 && m_popCount == 6)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 7;
	}
	
	if (TIMER_INSTANCE.GetPrevTimer() - TIMER_INSTANCE.GetTimer() >= 1 )
	{
		
	}

	TIMER_INSTANCE.Update();

	// �`��֐�����
	Draw();

	// �V�[���A�b�v�f�[�g
	SceneUpdate(result);
}

// �V�[���̃A�b�v�f�[�g(��Ɏ��V�[���ւ̑J�ڏ���)
void SceneInGame::SceneUpdate(SceneResult & result)
{
	// �^�C�}�[��0�ɂȂ�����A�Q�[���N���A�Ƃ��Ď��̃V�[����
	if (TIMER_INSTANCE.GetTimer() <= 0)
	{
		result.SetClear(true);
		toNext = 4;
	}

	// �v���C���[�����S��Ԃ�������A�Q�[���I�[�o�[�Ƃ��Ď��̃V�[����
	if (m_player->GetPlayerState() == m_player->PLAYER_STATE::DEAD)
	{
		result.SetClear(false);
		toNext = 4;
	}
}

// �`�揈��
void SceneInGame::Draw()
{
	// �I�u�W�F�N�g�̕`��
	m_obj->Draw();
	// �G�l�~�[�̕`��
	m_enemy->Draw();
	// �v���C���[�̕`��
	m_player->Draw();
	// UI�̕`��
	m_UI->Draw(*m_player->GetPlayerPointer());
	// �^�C�}�[�̕`��
	TIMER_INSTANCE.Draw();
}
