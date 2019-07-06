//-----------------------------------------------------------+
// NPC�}�l�[�W���[�N���X
//      : NPC�֘A(��G��)�̑����I�ȏ������s��
//                                  Last Update : 2019/07/02
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Idol.h"

class NpcManager final
{
public:
	NpcManager();                 // �R���X�g���N�^
	~NpcManager();                // �f�X�g���N�^      

	void Initialize();            // �e�평����

	void Delete();                // �e��������

	void Update(float deltaTime);                // �X�V

	void Draw();                  // �`��

private:

	int m_idolSourceHandle;        // �A�C�h���̃��f���n���h��

	Actor* m_idol;                 // �A�C�h��
};