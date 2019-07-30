//-----------------------------------------------------------------+
// �C���^�[�t�F�[�X���N���X
//      : �e�Q�[���V�[���ɂ�����C���^�[�t�F�[�X�̊��N���X
//                                        Last Update : 2019/07/10
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