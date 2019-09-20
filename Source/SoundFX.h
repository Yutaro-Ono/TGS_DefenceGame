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

	SoundFX(const char* in_fileName);        // �R���X�g���N�^
	~SoundFX();                              // �f�X�g���N�^

	void Initialize();                       // ����������

	void Delete();                           // �������

	void PlaySoundFx();                      // �T�E���h�Đ��֐�

	void PlayLoopSoundFx();                  // �T�E���h�̃��[�v�Đ�

	void StopSoundFx();                      // �Đ����̃T�E���h��~

	// �����y�t�@�C�����Đ����Ă��邩�ǂ����H
	bool ScanNowPlaySound();

private:

	int m_sourceSoundHandle;                 // ���y�t�@�C���̃n���h��
	
};