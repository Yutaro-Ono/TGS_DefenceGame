//----------------------------------------------------------+
// �v���C���[�}�l�[�W���[�N���X
//      : �v���C���[�̍X�V�͂����ōs��
//                                 Last Update : 2019/07/01
//----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "Actor.h"

class Actor;

class PlayerManager final
{
public:
	
	PlayerManager();         // �R���X�g���N�^
	~PlayerManager();        // �f�X�g���N�^

	void Initialize();       // �v���C���[����������

	void Delete();           // �폜����

	void Update();           // �X�V����

	void Draw();             // �`�揈��

	// ���������v���C���[�ւ̃|�C���^���擾����
	// ��ɃJ�����̏����ɗp����
	Actor* GetPlayerPointer() { return m_player; }

private:

	int m_sourceModelHandle;      // ���f���n���h��
	Actor* m_player;              // �v���C���[



};