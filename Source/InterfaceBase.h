//-----------------------------------------------------------------+
// �C���^�[�t�F�[�X���N���X
//      : �e�Q�[���V�[���ɂ�����C���^�[�t�F�[�X�̊��N���X
//                                                2019 Yutaro Ono.
//-----------------------------------------------------------------+
#pragma once

class InterfaceBase
{

public:

	InterfaceBase();
	~InterfaceBase();

	virtual void Initialize() = 0;

	virtual void Update() = 0;

};