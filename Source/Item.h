//-----------------------------------------------------------+
// �A�C�e���N���X
//      : �A�C�e��
//                                  Last Update : 2019/07/12
//-----------------------------------------------------------+
#pragma once
#include "ObjectBase.h"

class Item : public ObjectBase
{
public:

	Item(int sourceModelHandle);
	~Item();

	void Initialize();

	void Update();

	void Draw() {};

private:


};