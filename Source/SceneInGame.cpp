//----------------------------------------------------------------------+
// in�Q�[��(�Q�[����)�V�[��                               
//                                              Last Update : 2019/07/13
//----------------------------------------------------------------------+
#include "SceneInGame.h"
#include "HitChecker.h"

const int SceneInGame::MAX_GAME_TIME = 60;

// �R���X�g���N�^
SceneInGame::SceneInGame()
{
	m_player = NULL;
	m_enemy = NULL;
	m_item = NULL;
	toNext = 3;
}

// �f�X�g���N�^
SceneInGame::~SceneInGame()
{
}

// �e�평��������
void SceneInGame::Initialize()
{
	// �^�C�}�[�𐶐��A������
	m_timer = new Timer();
	m_timer->Initialize();
	// �v���C���[�𐶐��C������
	m_player = new PlayerManager();
	m_player->Initialize();
	// �G�l�~�[�𐶐��C������
	m_enemy = new EnemyManager();
	m_enemy->Initialize();
	// �A�C�e���𐶐�
	m_item = new ItemManager();
	m_item->Initialize();
	// UI�𐶐��A������
	m_UI = new InGameUIManager();
	m_UI->Initialize();
	// �I�u�W�F�N�g�𐶐��C������
	m_obj = new ObjectManager();
	m_obj->Initialize();
	// �J�E���g�_�E�����o�̐����A������
	m_countdown = new CountDown();
	m_countdown->Initialize();

	m_setTimer = false;
	m_popCount = 0;
}

// �e��������
void SceneInGame::Delete()
{
	m_item->Delete();
	m_UI->Delete();

	delete (m_timer);
	delete (m_player);
	delete (m_enemy);
	delete (m_item);
	delete (m_obj);
	delete (m_UI);
	delete (m_countdown);
}

// �I�[�o�[���C�h�����A�b�v�f�[�g(�����Ȃ�)
void SceneInGame::Update(Camera & camera, Input& input, float deltaTime)
{
}

// �X�V����
void SceneInGame::Update(Camera& camera, Input& input, SceneResult& result, float deltaTime)
{
	// �J�E���g�_�E������(�{���̓J�E���g�_�E����p�̏󋵂����Ȃ���΂Ȃ�Ȃ�)
	m_countdown->StartCountDown();

	//------------------------------------------------------+
	// �^�C�}�[�̏�����
	//------------------------------------------------------+
	if (m_setTimer == false)
	{
		m_timer->Initialize();
		m_setTimer = true;
	}

	// �J�����̍X�V
	camera.Update(*m_player);

	//------------------------------------------------------+
	// �����蔻�菈��
	//------------------------------------------------------+
	// �v���C���[�ƃG�l�~�[
	HitChecker::CheckHit(*m_player, *m_enemy);
	// �G�l�~�[���m
	for (int i = 0; i < m_enemy->GetActiveEnemy(); i++)
	{
		HitChecker::CheckHitEnemy(*m_enemy, i);
	}
	// �v���C���[�ƃA�C�e��
	HitChecker::CheckHitItem(*m_player, *m_item);
	// �v���C���[�Ɖ���|�b�h
	HitChecker::CheckHitPod(*m_player, *m_obj);

	//------------------------------------------------------+
	// �v���C���[�̍X�V
	//------------------------------------------------------+
	m_player->Update(input, deltaTime);
	// �G�l�~�[�̍X�V
	m_enemy->Update(*m_player, deltaTime);
	// �A�C�e���̍X�V
	m_item->Update(deltaTime);
	// UI�̍X�V
	m_UI->Update(*m_player->GetPlayerPointer());
	// �I�u�W�F�N�g�̍X�V
	m_obj->Update();

	// �c�莞�Ԃɂ���ăG�l�~�[�ƃA�C�e����ǉ�
	if (m_timer->GetTimer() == 50 && m_popCount == 0)
	{
		m_enemy->AddEnemy();
		m_popCount = 1;
	}
	if (m_timer->GetTimer() == 45 && m_popCount == 1)
	{
		m_enemy->AddEnemy();
		m_popCount = 2;
	}
	if (m_timer->GetTimer() == 40 && m_popCount == 2)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 3;
	}
	if (m_timer->GetTimer() == 35 && m_popCount == 3)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 4;
	}
	if (m_timer->GetTimer() == 30 && m_popCount == 4)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 5;
	}
	if (m_timer->GetTimer() == 25 && m_popCount == 5)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();
		m_popCount = 6;
	}
	if (m_timer->GetTimer() == 20 && m_popCount == 6)
	{
		m_enemy->AddEnemy();
		m_enemy->AddEnemy();

		m_popCount = 7;
	}

	if (m_timer->GetTimer() % 10 == 0)
	{
		m_item->AddItem();
	}

	// �^�C�}�[�̍X�V
	m_timer->UpdateCountDown(MAX_GAME_TIME);

	// �`��֐�����
	Draw();

	// �V�[���A�b�v�f�[�g
	SceneUpdate(result);
}

// �V�[���̃A�b�v�f�[�g(���U���g�V�[���ւ̑J�ڏ���)
void SceneInGame::SceneUpdate(SceneResult & result)
{
	// �^�C�}�[��0�ɂȂ�����A�Q�[���N���A�Ƃ��Ď��̃V�[����
	if (m_timer->GetTimer() <= 0)
	{
		result.SetClear(true);      // �Q�[���𖳎��N���A����
		toNext = 4;                 // ���U���g��
	}

	// �v���C���[�����S��Ԃ�������A�Q�[���I�[�o�[�Ƃ��Ď��̃V�[����
	if (m_player->GetPlayerState() == m_player->PLAYER_STATE::DEAD)
	{
		result.SetClear(false);      // �Q�[���I�[�o�[�ƂȂ���
		toNext = 4;                  // ���U���g��
	}
}

void SceneInGame::PlaceEnemyByTime()
{
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
	m_timer->Draw();
}
