//---------------------------------------------------------------+
// �t�B�[���h�I�u�W�F�N�g�N���X
//      : �t�B�[���h�̌ŗL���� (�I�u�W�F�N�g���N���X���p��)
//                                      Last Update : 2019/07/01
//---------------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class ObjectField : public ObjectBase
{
public:

	ObjectField(int sourceModelHandle);
	~ObjectField();

	void Initialize() override;

	void Update() override;



private:



};