//-----------------------------------------------------------+
// �X�J�C�h�[���N���X
//      : �X�J�C�h�[��(��)�̕`������s
//                                  Last Update : 2019/07/02
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"
#include "ObjectBase.h"

class ObjectSky : public ObjectBase
{
public:

	ObjectSky(int sourceModelHandle);            // �R���X�g���N�^
	~ObjectSky();                                // �f�X�g���N�^

	void Initialize() override;                  // �e�평����

	void Update(float deltaTime) override;

private:

	static const VECTOR SCALE_SIZE;              // ���f���̊g�嗦
	static const VECTOR ROTATE_RAD;               // ���f���̉�]����
};