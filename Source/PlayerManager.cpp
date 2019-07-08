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
	
	if (m_sourceModelHandle <= -1)
	{
		printfDx("Player : ���f���ǂݍ��ݎ��s\n");
	}

	m_player = new Player(m_sourceModelHandle);
}

// �e��������
void PlayerManager::Delete()
{
}

// �X�V����
void PlayerManager::Update(Input& input, float deltaTime)
{
	m_player->Update(input, deltaTime);
	// �|�W�V�������Z�b�g
	MV1SetPosition(m_sourceModelHandle, VGet(0.0f, 0.0f, 0.0f));

}

// �`�揈��
void PlayerManager::Draw()
{
	m_player->Draw();


}
