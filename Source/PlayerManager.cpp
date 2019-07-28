//-----------------------------------------------------------------------+
// �v���C���[�}�l�[�W���[�N���X                                 
//                                              Last Update : 2019/07/01
//-----------------------------------------------------------------------+
#include "DxLib.h"
#include "PlayerManager.h"
#include "Actor.h"
#include "Player.h"

// �R���X�g���N�^
PlayerManager::PlayerManager()
	:m_sourceModelHandle(-1)
	,m_playerState(PLAYER_STATE::ACTIVE)
{
	m_player = NULL;
}

// �f�X�g���N�^
PlayerManager::~PlayerManager()
{
	MV1DeleteModel(m_sourceModelHandle);      // ���f���̍폜
	delete(m_player);
}

// �v���C���[���f����������
void PlayerManager::Initialize()
{
	// ���f����ǂݍ���
	m_sourceModelHandle = MV1LoadModel("Data/Model/Actor/Player/humster/model/humster.mv1");	
	// ���f���̃��[�h���s���ɕ\��
	if (m_sourceModelHandle <= -1)
	{
		printfDx("Player : ���f���ǂݍ��ݎ��s\n");
	}
	// �v���C���[����
	m_player = new Player(m_sourceModelHandle);
	// ������
	m_player->Initialize();
}

// �e��������
void PlayerManager::Delete()
{
}

// �X�V����
void PlayerManager::Update(float deltaTime)
{
	// �v���C���[�̍X�V
	m_player->Update(deltaTime);

	// �v���C���[�̗̑͂�0�ɂȂ����玀�S��Ԃɂ���
	if (m_player->GetHitPoint() <= 0)
	{
		m_playerState = PLAYER_STATE::DEAD;
	}
}

// �`�揈��
void PlayerManager::Draw()
{
	m_player->Draw();
}
