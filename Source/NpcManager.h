//-----------------------------------------------------------+
// NPC�}�l�[�W���[�N���X
//      : NPC�֘A(��G��)�̑����I�ȏ������s��
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "Actor.h"
#include "Idol.h"

class NpcManager final
{

public:

	NpcManager();                          // �R���X�g���N�^
	~NpcManager();                         // �f�X�g���N�^      

	void Initialize();                     // �e�평����

	void Delete();                         // �e��������

	void Update(float deltaTime);          // �X�V

	void Draw();                           // �`��


private:

	int     m_idolSourceHandle;          // �A�C�h���̃��f���n���h��

	Actor              *m_idol;                   // �A�C�h��

};