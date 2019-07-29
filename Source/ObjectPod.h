//-----------------------------------------------------------+
// ����|�b�h�N���X
//      : �A�C�e������p�̃|�b�h
//                                  Last Update : 2019/07/29
//-----------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class ObjectPod : public ObjectBase
{
public:

	ObjectPod(int sourceModelHandle);
	~ObjectPod();

	void Initialize();

	void Delete();

	void Update();



private:





	static const VECTOR INITIAL_POSITION;              // �|�b�h�̏������W(�Œ�l)
	static const float HIT_RADIUS;                     // �����蔻��p�̔��a�̒萔
};