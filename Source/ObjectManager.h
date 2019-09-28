//-----------------------------------------------------------+
// �I�u�W�F�N�g�}�l�[�W���[�N���X
//      : �I�u�W�F�N�g�̑����I�ȏ������s��
//                                         2019 Yutaro Ono.
//-----------------------------------------------------------+
#pragma once

// �C���N���[�h�t�@�C��
#include "DxLib.h"
#include <vector>
#include "Common.h"
#include "ObjectBase.h"
#include "ObjectField.h"
#include "ObjectPod.h"

class ObjectManager final
{

public:

	ObjectManager();                       // �R���X�g���N�^
	~ObjectManager();                      // �f�X�g���N�^

	void Initialize();                     // ����������
	void Delete();                         // �������

	void Update(float deltaTime);          // �X�V����

	void Draw();                           // �`�揈��

	//-------------------------------------------------------------+
    // Getter/Setter�֘A
    //-------------------------------------------------------------+

	ObjectBase* GetPodPointer() { return m_podObj; }          // ����|�b�h�̃|�C���^�Q�b�^�[


private:

	int       m_skySourceHandle;          // �X�J�C�h�[���̃n���h��
	int       m_podSourceHandle;          // ����|�b�h�̃n���h��
	int     m_fieldSourceHandle;          // �t�B�[���h���f���̃n���h��

	ObjectBase*        m_skyObj;          // ��
	ObjectBase*        m_podObj;          // ����|�b�h
	ObjectBase*      m_fieldObj;          // �t�B�[���h

};