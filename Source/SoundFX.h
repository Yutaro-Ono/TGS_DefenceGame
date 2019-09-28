//-----------------------------------------------------------+
// �T�E���h�N���X
//      : �T�E���h�֘A�̃��[�h�A�Đ����ꌳ�Ǘ�
//                                           2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"

class SoundFX final
{

public:

	SoundFX(const char* in_fileName);          // �R���X�g���N�^
	~SoundFX();                                // �f�X�g���N�^

	void Initialize();                         // ����������

	void Delete();                             // �������

	void PlaySoundFx();                        // �T�E���h�Đ��֐�

	void PlayLoopSoundFx();                    // �T�E���h�̃��[�v�Đ�

	void StopSoundFx();                        // �Đ����̃T�E���h��~

	bool ScanNowPlaySound();                   // �����y�t�@�C�����Đ����Ă��邩�ǂ����H


private:

	int m_sourceSoundHandle;                   // ���y�t�@�C���̃n���h��
	
};