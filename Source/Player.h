//-----------------------------------------------------------+
// �v���C���[�N���X
//      : �v���C���[�̌ŗL���� (�A�N�^�[�N���X���p��)
//                                  Last Update : 2019/07/02
//-----------------------------------------------------------+
#pragma once
#include "Actor.h"
#include "Input.h"

class Player : public Actor
{
public:
	Player(const int sourceModelHandle);   // �R���X�g���N�^
	~Player();                             // �f�X�g���N�^

	void Initialize() override {};

	void Delete() override {};

	void Update() override;     // �v���C���[�֘A�̍X�V


private:

};

