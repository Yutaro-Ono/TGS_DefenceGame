//----------------------------------------------------------+
// �v���C���[�}�l�[�W���[�N���X
//      : �v���C���[�̍X�V�͂����ōs��
//                                 Last Update : 2019/07/01
//----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Input.h"
#include "Actor.h"
#include "Player.h"
class Input;
class Actor;
class Player;

class PlayerManager final
{
public:
	
	enum PLAYER_STATE
	{
		ACTIVE = 0,
		DEAD,
	};

	PlayerManager();         // �R���X�g���N�^
	~PlayerManager();        // �f�X�g���N�^

	void Initialize();       // �v���C���[����������

	void Delete();           // �폜����

	void Update(float deltaTime);           // �X�V����

	void Draw();             // �`�揈��

	const int& GetPlayerState() { return m_playerState; }       // �v���C���[�̏�Ԋm�F�p

	// ���������v���C���[�ւ̃|�C���^���擾����
	// ��ɃJ�����̏����ɗp����
	Player* GetPlayerPointer() { return m_player; }

private:

	int m_playerState;            // �v���C���[�̏�Ԋi�[

	int m_sourceModelHandle;      // ���f���n���h��
	Player* m_player;             // �v���C���[



};