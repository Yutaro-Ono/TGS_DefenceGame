//-----------------------------------------------------------+
// �X�J�C�h�[���N���X
//      : �X�J�C�h�[��(��)�̕`������s
//                                          2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include "ObjectBase.h"

class ObjectSky : public ObjectBase
{

public:

	ObjectSky(int sourceModelHandle);               // �R���X�g���N�^
	~ObjectSky();                                   // �f�X�g���N�^

	void Initialize() override;                     // �e�평����

	void Update(float deltaTime) override;          // �X�V����


private:

	static const VECTOR SCALE_SIZE;          // ���f���̊g�嗦
	static const VECTOR ROTATE_RAD;          // ���f���̉�]����

};