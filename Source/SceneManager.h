//---------------------------------------------------------------------+
// �V�[���}�l�[�W���[�N���X
//      : �V�[�������𑍍��I�ɊǗ�����N���X�����A�����_�ł͖�����
//                                                   2019 Yutaro Ono.
//---------------------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"

class SceneManager final
{

public:

	SceneManager();             // �R���X�g���N�^
	~SceneManager();            // �f�X�g���N�^

	void Initialize();          // �e�평��������

	void Delete();              // �e��������

	void Update();              // �X�V����

};