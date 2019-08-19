//-----------------------------------------------------------+
// �T�E���h�N���X
//      : �T�E���h�֘A�̃��[�h�A�Đ����ꌳ�Ǘ�
//                                  Last Update : 2019/07/13
//-----------------------------------------------------------+
#pragma once
#include "DxLib.h"



class SoundFX final
{
public:

	//enum SFX_MENU
	//{
	//	ENTER,
	//	CURSOL,
	//	ALL_NUM,
	//};

	//enum SFX_PLAYER
	//{
	//	MOVE,
	//	ALL_NUM,
	//};

	//enum SFX_ENEMY
	//{
	//	MOVE,
	//	ALL_NUM,
	//};

	SoundFX(const char* in_fileName);        // �R���X�g���N�^
	~SoundFX();       // �f�X�g���N�^

	void Initialize();     // ����������

	void Delete();         // �������

	void PlaySoundFx();    // �T�E���h�Đ��֐�

	void PlayLoopSoundFx();  // �T�E���h�̃��[�v�Đ�

	void StopSoundFx();      // �Đ����̃T�E���h��~

private:

	int m_sourceSoundHandle;

	//int m_menuSFXHandle[SFX_MENU::ALL_NUM];         // ���j���[SE�̃n���h��

	//int m_playerSFXHandle[SFX_PLAYER::ALL_NUM];     // �v���C���[SE�̃n���h��
	
};